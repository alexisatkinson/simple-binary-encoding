/* Generated class message */
#ifndef _SERIALIZEDFRAME_HPP_
#define _SERIALIZEDFRAME_HPP_

#include "sbe/sbe.hpp"

#include "uk_co_real_logic_sbe_ir_generated/VarDataEncoding.hpp"
#include "uk_co_real_logic_sbe_ir_generated/SerializedSignal.hpp"
#include "uk_co_real_logic_sbe_ir_generated/SerializedPrimitiveType.hpp"
#include "uk_co_real_logic_sbe_ir_generated/SerializedByteOrder.hpp"

using namespace sbe;

namespace uk_co_real_logic_sbe_ir_generated {

class SerializedFrame : public MessageFlyweight
{
private:
    char *buffer_;
    int offset_;
    int position_;

public:

    sbe_uint64_t blockLength(void) const
    {
        return 8;
    };

    sbe_uint64_t offset(void) const
    {
        return offset_;
    };

    SerializedFrame &reset(char *buffer, const int offset)
    {
        buffer_ = buffer;
        offset_ = offset;
        position(offset + blockLength());
        return *this;
    };

    sbe_uint64_t position(void) const
    {
        return position_;
    };

    void position(const sbe_uint64_t position)
    {
        position_ = position;
    };

    int size(void) const
    {
        return position() - offset_;
    };

    int templateId(void) const
    {
        return 1;
    };

    char *buffer(void)
    {
        return buffer_;
    };

    MessageFlyweight *message(void)
    {
        return this;
    };

    int sbeIrVersionId(void) const
    {
        return 1;
    };


    sbe_int32_t sbeIrVersion(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_32(*((sbe_int32_t *)(buffer_ + offset_ + 0)));
    };

    SerializedFrame &sbeIrVersion(const sbe_int32_t value)
    {
        *((sbe_int32_t *)(buffer_ + offset_ + 0)) = SBE_LITTLE_ENDIAN_ENCODE_32(value);
        return *this;
    };

    int schemaVersionId(void) const
    {
        return 2;
    };


    sbe_int32_t schemaVersion(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_32(*((sbe_int32_t *)(buffer_ + offset_ + 4)));
    };

    SerializedFrame &schemaVersion(const sbe_int32_t value)
    {
        *((sbe_int32_t *)(buffer_ + offset_ + 4)) = SBE_LITTLE_ENDIAN_ENCODE_32(value);
        return *this;
    };

    const char *packageValCharacterEncoding()
    {
        return "UTF-8";
    };

    int packageValId(void) const
    {
        return 4;
    };

    int getPackageVal(char *dst, const int length)
    {
        sbe_uint64_t sizeOfLengthField = 1;
        sbe_uint64_t lengthPosition = position();
        position(lengthPosition + sizeOfLengthField);
        sbe_uint64_t dataLength = (*((sbe_uint8_t *)(buffer_ + lengthPosition)));
        int bytesToCopy = (length < dataLength) ? length : dataLength;
        ::memcpy(dst, buffer_ + position(), bytesToCopy);
        position(position() + (sbe_uint64_t)dataLength);
        return bytesToCopy;
    };

    int putPackageVal(const char *src, const int length)
    {
        sbe_uint64_t sizeOfLengthField = 1;
        sbe_uint64_t lengthPosition = position();
        *((sbe_uint8_t *)(buffer_ + lengthPosition)) = ((sbe_uint8_t)length);
        position(lengthPosition + sizeOfLengthField);
        ::memcpy(buffer_ + position(), src, length);
        position(position() + (sbe_uint64_t)length);
        return length;
    };
};
}
#endif
