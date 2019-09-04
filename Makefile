macro_definition:
PROJECT_DIR=C:\Projetos\caiuxo\conversor-unidades
BUILD_DIR=$(PROJECT_DIR)\build
TEST_EXE=Test.exe
CONVERSOR_EXE=Conversor.exe

print_info:
	@echo.
	@echo ====== Environment Information ======
	@echo.
	@echo PROJECT_DIR = $(PROJECT_DIR)
	@echo BUILD_DIR = $(BUILD_DIR)

clean_build:
	del /s /q *.obj
	del /s /q *.exe

build: clean_build macro_definition print_info
	cl /Fe$(BUILD_DIR)\$(CONVERSOR_EXE) ConvertFormats.c EntryPoint.c
	$(BUILD_DIR)\$(CONVERSOR_EXE)

run_tests: clean_build macro_definition print_info
	cl /Fe$(BUILD_DIR)\$(TEST_EXE) ConvertFormats.c Tests.c
	$(BUILD_DIR)\$(TEST_EXE)

all: build run_tests
