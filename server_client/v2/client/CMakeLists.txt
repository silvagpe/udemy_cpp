cmake_minimum_required(VERSION 3.16..3.28)

# Nome do projeto
project(ClientCSV VERSION 0.0.1)

# Especifica a versão do padrão C++ que queremos usar
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# include_directories(include)
# Adiciona o Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Buscar todos os arquivos .cpp do diretório src/csv
file(GLOB CSV_SOURCES "src/csv/*.cpp")
file(GLOB CLIENT_SERVICE_SOURCES "src/client_service/*.cpp")

# Adiciona o executável que será gerado a partir dos arquivos .cpp
add_executable(client_csv src/main.cpp src/csv/csv_reader.cpp ${CSV_SOURCES} ${CLIENT_SERVICE_SOURCES})

# Linka a biblioteca do Google Test
target_link_libraries(client_csv ${GTEST_LIBRARIES} pthread)

# Linka bibliotecas (se necessário)
# target_link_libraries(client_csv stdc++fs)
# target_link_libraries(meu_programa minha_biblioteca)