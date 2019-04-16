#ifndef MODULE_EMULATOR_BISS_H
#define MODULE_EMULATOR_BISS_H

#ifdef WITH_EMU

#if defined(DVBCISSA_BISS2)
#include <openssl/rsa.h>

#define BISS2_MAX_RSA_KEYS 16

typedef struct biss2_rsa_key
{
	uint8_t ekid[8];
	RSA *key;
} biss2_rsa_key_t;

int8_t biss_ecm(struct s_reader *rdr, uint16_t caid, const uint8_t *ecm, uint8_t *dw, uint16_t srvid, uint16_t ecmpid, EXTENDED_CW *cw_ex);
int8_t biss_emm(struct s_reader *rdr, const uint8_t *emm, uint32_t *keysAdded);
uint16_t biss_read_pem(struct s_reader *rdr, uint8_t max_keys);
#else
int8_t biss_ecm(struct s_reader *rdr, uint16_t caid, const uint8_t *ecm, uint8_t *dw, uint16_t srvid, uint16_t ecmpid);
#endif // DVBCISSA_BISS2

#endif // WITH_EMU

#endif // MODULE_EMULATOR_BISS_H
