/*
* SHA-{384,512}
* (C) 1999-2007 Jack Lloyd
*
* Distributed under the terms of the Botan license
*/

#ifndef BOTAN_SHA_64BIT_H__
#define BOTAN_SHA_64BIT_H__

#include <botan/mdx_hash.h>

namespace Botan {

/**
* Base class for the 64-bit SHA-2 hashes (SHA-384 and SHA-512)
*/
class BOTAN_DLL SHA_384_512_BASE : public MDx_HashFunction
   {
   protected:
      void clear();

      /**
      * @param out output size in bytes
      */
      SHA_384_512_BASE(u32bit out) :
         MDx_HashFunction(out, 128, true, true, 16) {}

      SecureVector<u64bit, 8> digest;
   private:
      void compress_n(const byte[], u32bit blocks);
      void copy_out(byte[]);

      SecureVector<u64bit, 80> W;
   };

/**
* SHA-384
*/
class BOTAN_DLL SHA_384 : public SHA_384_512_BASE
   {
   public:
      void clear();
      std::string name() const { return "SHA-384"; }
      HashFunction* clone() const { return new SHA_384; }
      SHA_384() : SHA_384_512_BASE(48) { clear(); }
   };

/**
* SHA-512
*/
class BOTAN_DLL SHA_512 : public SHA_384_512_BASE
   {
   public:
      void clear();
      std::string name() const { return "SHA-512"; }
      HashFunction* clone() const { return new SHA_512; }
      SHA_512() : SHA_384_512_BASE(64) { clear(); }
   };

}

#endif
