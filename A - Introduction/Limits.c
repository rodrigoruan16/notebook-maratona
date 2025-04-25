////////////////////////////////////
// Limites de representacao de dados
////////////////////////////////////

/* Tipos inteiros:
   Tipo            Bits   Faixa                     Precisao
   --------------- ------ ------------------------ -------- */
   char             8      0..127                   2
   signed char      8     -128..127                 2
   unsigned char    8      0..255                   2
   short            16    -32768..32767             4
   unsigned short   16    0..65535                  4
   int              32    -2*10^9..2*10^9           9
   unsigned int     32    0..4*10^9                 9
   int64_t          64    -9*10^18..9*10^18         18
   uint64_t         64    0..18*10^18               19

/* Tipos flutuante:
   Tipo            Bits   Expoente    Precisao
   --------------- ------ ---------- -------- */
   float           32     38          6
   double          64     308         15
   long double     80     19728       18