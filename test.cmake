# Check if all required arguments are provided
macro(argument_required argument failstring)
	if (NOT ${argument})
		message(FATAL_ERROR ${failstring})
	endif (NOT ${argument})
endmacro(argument_required)

argument_required(LIBRARY_FOLDER "All tests require to have a library output folder.")
argument_required(TESTS_DIRECTORY "All tests require to have a test folder.")
argument_required(TEST_FILENAME "All tests require a trace filename to be reprinted.")
argument_required(CALLS "All tests require a call count.")

# Enable different GLES version tests
if (GLES_FORCED)
	set(GLES${GLES_FORCED}_ENABLED ON)
else (GLES_FORCED)
	set(GLES1_ENABLED ON)
	set(GLES2_ENABLED ON)
endif (GLES_FORCED)

# Special case fo pixels tolerance
if (TOLERANCE)
	set(TOLERANCE_GLES1 ${TOLERANCE})
	set(TOLERANCE_GLES2 ${TOLERANCE})
endif (TOLERANCE)

# Use the built library
set(ENV{LD_LIBRARY_PATH} ${LIBRARY_FOLDER}:$ENV{LD_LIBRARY_PATH})

macro(run_test GLES toler)
	set(ENV{LIBGL_ES} ${GLES})

	message(STATUS "Starting test in GLES $ENV{LIBGL_ES}...")
	execute_process(
		COMMAND ${TESTS_DIRECTORY}/test.sh
		 ${TEST_FILENAME}
		 ${CALLS}
		 ${toler}
		 ${EXTRACT_RANGE}
		ERROR_VARIABLE TEST_ERROR
		OUTPUT_VARIABLE TEST_OUTPUT
		WORKING_DIRECTORY ${TESTS_DIRECTORY}
	)
	message(STATUS "Ran test.\nError: ${TEST_ERROR}\nOutput: ${TEST_OUTPUT}")
	
	if (TEST_ERROR)
		message(FATAL_ERROR "Test failed while using GLES $ENV{LIBGL_ES}.\n${TEST_ERROR}")
	endif (TEST_ERROR)
endmacro(run_test)

# Run the test using GLES 1, if not disabled
if (GLES1_ENABLED)
	argument_required(TOLERANCE_GLES1 "All tests require a pixel tolerance for GLES 1.")
	run_test(1 ${TOLERANCE_GLES1})
endif (GLES1_ENABLED)

# Run the test using GLES 2, if not disabled
if (GLES2_ENABLED)
	argument_required(TOLERANCE_GLES2 "All tests require a pixel tolerance for GLES 2.")
	run_test(2 ${TOLERANCE_GLES2})
endif (GLES2_ENABLED)

message(STATUS "Success.")
