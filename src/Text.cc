#include "../ext/googletest/googletest/include/gtest/gtest.h"
#include "curso.h"

TEST (crearCurso, EJEMPLO1){
    EXPECT_TRUE(crearCurso());
}