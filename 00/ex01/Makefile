NAME		:=	goldfish_phonebook

CXX			:=	c++
CXXFLAGS	:=	-Wall -Werror -Wextra -std=c++98 -pedantic
CXXFLAGS	+=	-g
# CXXFLAGS	+=	-Wno-unused-variable -Wno-unused-parameter -Wno-unused-function

SRC_DIR		:=	srcs
SRCS		:=	$(shell find ${SRC_DIR} -name "*.cpp")
SRCS_T		:=	$(shell find ${SRC_DIR} -name "*.tpp")

LIB			:=	lib.a
LIB_DIR		:=	lib
LIB_MAKE	:=	make -C ${LIB_DIR}

ifdef SAN
CXXFLAGS	+=	-fsanitize=address -g -D SAN=1
LIB_MAKE	+=	SAN=1
endif

HEADER		:=	$(shell find ${SRC_DIR} -name "*.hpp")
CPPFLAGS	:=	$(addprefix -I, $(dir ${HEADER}) ${LIB_DIR}/include)

OBJ_DIR		:=	objs
OBJS 		:=	$(patsubst ${SRC_DIR}%.cpp, ${OBJ_DIR}%.o, ${SRCS})

GREY		:=	\033[30m
RED			:=	\033[31m
CYAN		:=	\033[36m
LIGHT_CYAN	:=	\033[1;36m
RESET		:=	\033[0m

all: ${NAME}

${OBJ_DIR}:
	@command="mkdir $@" && \
	printf "${GREY}$$command${RESET}\n"

${OBJ_DIR}/%.o: ${SRC_DIR}/%.cpp ${HEADER} ${SRCS_T} | ${OBJ_DIR}
	@mkdir -p ${@D}
	@printf "${CYAN}${CXX} ${CXXFLAGS} \$${CPPFLAGS} -c $< -o $@${RESET}\n"
	@${CXX} ${CXXFLAGS} ${CPPFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${LIB_MAKE}
	@command="${CXX} ${CXXFLAGS} $^ ${LIB_DIR}/${LIB} -o $@" && \
	printf "${LIGHT_CYAN}$$command${RESET}\n" && \
	$$command

clean:
	${LIB_MAKE} clean
	@command="${RM} -r ${OBJ_DIR}" && \
	printf "${RED}$$command${RESET}\n" && \
	$$command

fclean: clean
	${LIB_MAKE} fclean
	@command="${RM} ${NAME}" && \
	printf "${RED}$$command${RESET}\n" && \
	$$command

re:	fclean all
