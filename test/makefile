CXX = g++

TARGET	= test.out

SRCDIR = ../src

SRCS	= key_list_c.cpp\
	dynamic_mem_c.cpp\
	file_ptr_c.cpp\
	sha_c.cpp\
	file_enc.cpp\
	aes_c.cpp\
	key_gen_c.cpp\
	error.cpp\
	device_c.cpp

TESTSRC	= keyGenTest.cpp\
	key_list_test.cpp\
	test.cpp\
	dynamicMemTest.cpp\
	test_log.cpp\
	deviceTest.cpp

TESTDIR = src

OBJDIR = build

OBJS	= ${SRCS:%.cpp=${OBJDIR}/%.o} ${TESTSRC:%.cpp=${OBJDIR}/%.o}

LDGFLAGS	= -lpthread \
	-lgtest_main \
	-lgtest

LDFLAGS	= -lcrypto \
	-lssl \
	-pthread

CFLAGS	= -Wall\
	-std=c++11


${TARGET}: ${OBJS}
	${CXX} -o $@ $^ ${LDFLAGS} ${LDGFLAGS}

${OBJDIR}/%.o: $(SRCDIR)/%.cpp
	mkdir -p build
	cd build;\
	${CXX} -c ../$^ ${CFLAGS}

${OBJDIR}/%.o: $(TESTDIR)/%.cpp
	mkdir -p build
	cd build;\
	${CXX} -c ../$^ ${CFLAGS}

# %.o: ${addprefix ${SRCDIR},${SRCS}} ${TESTSRC}
# 	mkdir -p build
# 	cd build;\
# 	${CXX} ${addprefix ../, ${TESTSRC}} -c ${addprefix ../${SRCDIR},${SRCS}} ${CFLAGS}

run: ${TARGET}
	./${TARGET}

clean:
	rm -rf ${OBJDIR}/*.o ${TARGET}

debug:
	make clean
	make "CFLAGS = ${CFLAGS} -g -O0"
