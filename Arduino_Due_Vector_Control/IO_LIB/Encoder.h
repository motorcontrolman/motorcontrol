extern int8_t enc_6count;
extern int16_t enc_count;
extern const int16_t pinA ;
extern const int16_t pinB ;
extern const int16_t pinZ ;

void encoderInit();
extern int16_t encoderRead();
void count_inc();
void count_dec();
void enc_changedPinA();
void enc_changedPinB();
void enc_changedPinZ();
