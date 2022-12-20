#include "../ext/googletest/googletest/include/gtest/gtest.h"
#include "../include/curso.h"
//test para ver si sigue bien los distintos caminos tenidos en cuenta

TEST(registrarUsuario, t3){
    Persona person;
    person.dni="12345678D";
    person.contrasena="1";
    person.nombre="ELena";
    person.apellidos="Molero";
    person.correo="ele@gmail.com";
    EXPECT_EQ(true, registrarUsuario(person));//usuario que se registra
    EXPECT_EQ(false, registrarUsuario(person)); //ya se encontraba registrado
    person.dni="12345678";
    EXPECT_EQ(false, registrarUsuario(person));//dni no apropiado
    person.dni="12345678E";
    person.nombre="1";
    EXPECT_EQ(false, registrarUsuario(person));//el nombre no puede ser un numero
    person.nombre="ELena";
    person.apellidos="1";
    EXPECT_EQ(false, registrarUsuario(person));//los apellidos no pueden ser un numero
}
/*
//PRECONDICIONES:que no haya ya creado un curso llamado como curso.nombre
TEST(crearCurso, t4){
    Curse curso;
    curso.nombre="religion";
    curso.descripcion="atomos";
    curso.ponentes="4";
    curso.duracion="5";
    curso.aforo="5";
    curso.plibre="4";
    EXPECT_EQ(true, crearCurso(curso));//se crea curso
    EXPECT_EQ(false, crearCurso(curso));//dos cursos con el mismo nombre debe dar false
    curso.nombre="1";
    EXPECT_EQ(false, crearCurso(curso));//el nombre de un curso no puede ser un numero
    curso.nombre="religion";
    curso.descripcion="1";
    EXPECT_EQ(false, crearCurso(curso));//la descripcion de un curso no puede ser un numero
    curso.descripcion="atomos";
    curso.ponentes="Carla";
    EXPECT_EQ(false, crearCurso(curso));//el numero de ponentes no puede ser un string
    curso.ponentes="4";
    curso.duracion="mucho";
    EXPECT_EQ(false, crearCurso(curso));//la duracion no puede ser un string CAMBIAR ESTO EN EL CURSO.CC PORQUE REALMENTE ES STRING NO INT
    curso.duracion="5";
    curso.aforo="mucho";
    EXPECT_EQ(false, crearCurso(curso));//el aforo no puede ser un string
    curso.aforo="5";
    curso.plibre="muchas";
    EXPECT_EQ(false, crearCurso(curso));//el numero de plazas libres no puede ser un string
}
/*
//PRECONDICIONES: que estén registrados los dos usuarios que nombramos
TEST(login, t1){
    EXPECT_EQ(false, loginUsuario("1234567", "1234"));
    EXPECT_EQ(true, loginUsuario("12345678C", "coordinadorcurso")); //coord que sí esta registrado en nuestro fichero
    EXPECT_EQ(true, loginUsuario("12345678A", "1"));//usuario resgistrado
    EXPECT_EQ(false, loginUsuario("12345678C", "1234"));//contraseña incorrecta
    EXPECT_EQ(false, loginUsuario("12345678A", "1234"));//usuario no resgistrado
}

//PRECONDICIONES:que se haya creado el curso mates y no se haya registrado aun
TEST(inscribir, t2){
    EXPECT_EQ(true, inscribirse("12345678A", "quimica"));//se inscribe o queda en lista de espera en un curso que existe
    EXPECT_EQ(false, inscribirse("12345678A", "lengua"));//se inscribeo queda en lista de espera en un curso que no existe
    EXPECT_EQ(false, inscribirse("12345678A", "quimica"));//este usuario ya se ha inscrito antes en ese curso
}

*/
/*
//PRECONDICIONES: QUE EXISTA MATES PERO NO GEOGRAFIA
TEST(muestracurso, t5){
    std::string nombre="religion";
    EXPECT_EQ(true, muestraCurso(nombre));
    nombre="geografia";
    EXPECT_EQ(false, muestraCurso(nombre));

}

TEST (modificaCurso, test2){
    Curse curso;
    curso.nombre="religion";
    curso.descripcion="trigonometria";
    curso.ponentes="4";
    curso.duracion="4";
    curso.aforo="4";
    curso.plibre="4";
    EXPECT_TRUE(modificarCurso(curso));//curso correcto que existe
    curso.descripcion="1";
    EXPECT_FALSE(modificarCurso(curso));//campo incorrecto
    curso.descripcion="trigonometria";
    curso.ponentes="muchos";
    EXPECT_FALSE(modificarCurso(curso));//campo incorrecto
    curso.ponentes="4";
    curso.duracion="muchos";
    EXPECT_FALSE(modificarCurso(curso));//campo incorrecto
    curso.duracion="4";
    curso.aforo="muchos";
    EXPECT_FALSE(modificarCurso(curso));//campo incorrecto
    curso.aforo="4";
    curso.plibre="muchos";
    EXPECT_FALSE(modificarCurso(curso));//campo incorrecto
}
*/
int main(int argc, char** argv){
    ::testing::InitGoogleTest(&argc, argv);
    //menuPrincipal();
    return RUN_ALL_TESTS();
}
