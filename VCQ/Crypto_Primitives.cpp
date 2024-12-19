#include "../include/VCQ/Crypto_Primitives.h"
#include <openssl/conf.h>
#include <openssl/evp.h>
#include <openssl/err.h>
#include <openssl/rand.h>
#include <openssl/sha.h>
#include <iostream>
#include <cstring>
#include <iomanip> 

int Crypto_Primitives::sym_encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key,
                                   unsigned char *iv, unsigned char *ciphertext)
{
    EVP_CIPHER_CTX *ctx;

    int len;

    int ciphertext_len;

    /* Create and initialise the context */
    if (!(ctx = EVP_CIPHER_CTX_new()))
        std::cout << "create cipher ctx failed" << std::endl;

    /*
     * Initialise the encryption operation. IMPORTANT - ensure you use a key
     * and IV size appropriate for your cipher
     * In this example we are using 256 bit AES (i.e. a 256 bit key). The
     * IV size for *most* modes is the same as the block size. For AES this
     * is 128 bits
     */
    if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        std::cout << "encrypt init failed" << std::endl;

    /*
     * Provide the message to be encrypted, and obtain the encrypted output.
     * EVP_EncryptUpdate can be called multiple times if necessary
     */
    if (1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len))
        std::cout << "encrypt update failed" << std::endl;
    ciphertext_len = len;

    /*
     * Finalise the encryption. Further ciphertext bytes may be written at
     * this stage.
     */
    if (1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len))
        std::cout << "encrypt final failed" << std::endl;
    ciphertext_len += len;

    /* Clean up */
    EVP_CIPHER_CTX_free(ctx);

    return ciphertext_len;
}

int Crypto_Primitives::sym_decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key,
                                   unsigned char *iv, unsigned char *plaintext) {
    EVP_CIPHER_CTX *ctx;

    int len;

    int plaintext_len;

    /* Create and initialise the context */
    if(!(ctx = EVP_CIPHER_CTX_new()))
        std::cout<<"create cipher ctx failed"<<std::endl;

    /*
     * Initialise the decryption operation. IMPORTANT - ensure you use a key
     * and IV size appropriate for your cipher
     * In this example we are using 256 bit AES (i.e. a 256 bit key). The
     * IV size for *most* modes is the same as the block size. For AES this
     * is 128 bits
     */
    if(1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        std::cout<<"decrypt init failed"<<std::endl;

    /*
     * Provide the message to be decrypted, and obtain the plaintext output.
     * EVP_DecryptUpdate can be called multiple times if necessary.
     */
    if(1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len))
        std::cout<<"decrypt update failed"<<std::endl;
    plaintext_len = len;

    /*
     * Finalise the decryption. Further plaintext bytes may be written at
     * this stage. 
     * 对于输入恰好是16字节的整数的情况，无需进行这一步
     */
    if(ciphertext_len%16!=0 && 1 != EVP_DecryptFinal_ex(ctx, plaintext + len, &len))
        std::cout<<"decrypt final failed"<<std::endl;
    plaintext_len += len;

    /* Clean up */
    EVP_CIPHER_CTX_free(ctx);

    return plaintext_len;
}


std::string Crypto_Primitives::get_rand(int num){
    char* buf=new char[num];
    int rc = RAND_bytes((unsigned char*)buf, num);
    if(rc != 1) 
        std::cout<<"generate RAND_bytes failed"<<std::endl;
    return std::string(buf,num);
}


void Crypto_Primitives::get_prf(unsigned char* k,unsigned char* data,int len, unsigned char* v){
    std::string temp = std::string((char*)k,32) + std::string((char*)data,len);
    std::string sv = Crypto_Primitives::sha256(temp.c_str());
    std::memcpy(v, sv.c_str(), 32);
}



void Crypto_Primitives::string_xor(char* a,char* b,int len,char* res){
    for(int i=0;i<len;i++){
        res[i] = a[i] ^ b[i];
    }
}



void Crypto_Primitives::string2char(std::string str,char* c){
    int len=str.length();
    for(int i=0;i<len;i++){
        c[i]=str[i];
    }
}



void Crypto_Primitives::SHA512_digest(const unsigned char *message, size_t message_len, 
unsigned char* digest, unsigned int *digest_len)
{
    EVP_MD_CTX *mdctx;

    if ((mdctx = EVP_MD_CTX_new()) == NULL)
        std::cout<<"create ctx error"<<std::endl;

    if (1 != EVP_DigestInit_ex(mdctx, EVP_sha512(), NULL))
        std::cout<<"digest init error"  <<std::endl;

    if (1 != EVP_DigestUpdate(mdctx, message, message_len))
        std::cout<< "digest update error" <<std::endl;

    unsigned char* s;

    if ((s = (unsigned char *)OPENSSL_malloc(EVP_MD_size(EVP_sha512()))) == NULL)
        std::cout<< "memory alloc error" <<std::endl;

    if (1 != EVP_DigestFinal_ex(mdctx, s, digest_len))
        std::cout<< "digest final error" <<std::endl;
    
    // 复制
    memcpy(digest,s,*digest_len);
    // 释放内存
    OPENSSL_free(s);

    EVP_MD_CTX_free(mdctx);
}




void Crypto_Primitives::SHA256_digest(const unsigned char *message, size_t message_len, 
unsigned char* digest, unsigned int *digest_len)
{
    EVP_MD_CTX *mdctx;

    if ((mdctx = EVP_MD_CTX_new()) == NULL)
        std::cout<<"create ctx error"<<std::endl;

    if (1 != EVP_DigestInit_ex(mdctx, EVP_sha256(), NULL))
        std::cout<<"digest init error"  <<std::endl;

    if (1 != EVP_DigestUpdate(mdctx, message, message_len))
        std::cout<< "digest update error" <<std::endl;

    unsigned char* s;

    if ((s = (unsigned char *)OPENSSL_malloc(EVP_MD_size(EVP_sha256()))) == NULL)
        std::cout<< "memory alloc error" <<std::endl;

    if (1 != EVP_DigestFinal_ex(mdctx, s, digest_len))
        std::cout<< "digest final error" <<std::endl;
    
    // 复制
    memcpy(digest,s,*digest_len);
    // 释放内存
    OPENSSL_free(s);

    EVP_MD_CTX_free(mdctx);
}

std::string Crypto_Primitives::sha256(const char* data) {
	unsigned char res[32];
	SHA256_CTX* ctx = new SHA256_CTX();
    SHA256_Init(ctx);
    SHA256_Update(ctx,data,strlen(data));
    SHA256_Final(res,ctx);
	// Utils::print_bytes((uint8_t*)data, strlen((const char*)data));
	// print_bytes((uint8_t*)res, strlen((const char*)res));
	std::string sha256_hash;
	for(int i=0;i<32;i++){
		sha256_hash+=res[i];
	}
    return sha256_hash;
}

int Crypto_Primitives::enc_aes_gcm(const unsigned char *plaintext, int plaintext_len,
                const unsigned char *key,
                unsigned char *ciphertext)
{
  
    unsigned char output[AESGCM_MAC_SIZE+ AESGCM_IV_SIZE + plaintext_len*2] = {0};
    memcpy(output+AESGCM_MAC_SIZE,gcm_iv,AESGCM_IV_SIZE);
    
    int ciphertext_len=0, final_len=0;
  
    EVP_CIPHER_CTX *ctx= EVP_CIPHER_CTX_new();
    EVP_EncryptInit(ctx, EVP_aes_128_gcm(),key, gcm_iv);

    EVP_EncryptUpdate(ctx, output+ AESGCM_MAC_SIZE+ AESGCM_IV_SIZE, &ciphertext_len, plaintext, plaintext_len);
    EVP_EncryptFinal(ctx, output+ AESGCM_MAC_SIZE+ AESGCM_IV_SIZE + ciphertext_len, &final_len);
    EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_GCM_GET_TAG, AESGCM_MAC_SIZE, output);
    EVP_CIPHER_CTX_free(ctx);

    ciphertext_len = AESGCM_MAC_SIZE+ AESGCM_IV_SIZE + ciphertext_len + final_len;
    memcpy(ciphertext,output,ciphertext_len);
    
    return ciphertext_len;
    
}

int Crypto_Primitives::dec_aes_gcm(unsigned char *ciphertext, int ciphertext_len,
                const unsigned char *key,
                unsigned char *plaintext)
{
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    int plaintext_len=0, final_len=0;
    
    EVP_DecryptInit(ctx, EVP_aes_128_gcm(), key, gcm_iv);
    EVP_DecryptUpdate(ctx, plaintext, &plaintext_len, 
                      ciphertext+AESGCM_MAC_SIZE+AESGCM_IV_SIZE, 
                      ciphertext_len - AESGCM_MAC_SIZE - AESGCM_IV_SIZE);

    EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_GCM_SET_TAG, AESGCM_MAC_SIZE, ciphertext);
    EVP_DecryptFinal(ctx, plaintext + plaintext_len, &final_len);
    EVP_CIPHER_CTX_free(ctx);
    plaintext_len = plaintext_len + final_len;

    return plaintext_len;
}

void Crypto_Primitives::padding(std::string input, int pad2Len, unsigned char* output){
    //128 bit = 16 B
    int len = input.length();
    for(int i=0;i<pad2Len-len;i++){
        input += "#";
    }
    memcpy(output,(unsigned char*)input.c_str(),pad2Len);
}

std::string Crypto_Primitives::DePatch(unsigned char* input, int pad2Len){
    std::string output;
    for(int i=0;i<pad2Len;i++){
        if(input[i] == '#'){
            break;
        }
        output += input[i];
    }
    return output;
}

void Crypto_Primitives::print_string(std::string str){
    // 遍历字符串的每个字符
    for (char c : str) {
        // 输出每个字符的十六进制值
        std::cout << std::hex << std::setw(2) << std::setfill('0') 
                  << (int)(unsigned char)c << " ";  // 需要转换为 unsigned char 类型来处理负值
    }
    std::cout<<std::endl;
}
