#ifndef CSV_READER_H
#define CSV_READER_H

#include <iostream>

namespace csv_client::csv::csv_reader
{
    class CsvReader
    {
    private:
        // Atributos privados (se necessário)
    public:
        CsvReader();   // Declaração do construtor
        ~CsvReader();  // Declaração do destrutor
        /// @brief Abre o arquivo csv para leitura
        void openFile();  // Declaração do método openFile
    };

} // namespace csv_client::csv::csv_reader

#endif // CSV_READER_H
