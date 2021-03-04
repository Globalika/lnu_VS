using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Threading.Tasks;

namespace task1
{
    using System;
    using System.Globalization;

    /// <summary>
    /// A class to allow the conversion of doubles to string representations of
    /// their exact decimal values. The implementation aims for readability over
    /// efficiency.
    /// </summary>
    public class DoubleConverter
    {
        /// <summary>
        /// Converts the given double to a string representation of its
        /// exact decimal value.
        /// </summary>
        /// <param name="d">The double to convert.</param>
        /// <returns>A string representation of the double's exact decimal value.</return>
        public static string ToExactString(double d)
        {
            if (double.IsPositiveInfinity(d))
                return "+Infinity";
            if (double.IsNegativeInfinity(d))
                return "-Infinity";
            if (double.IsNaN(d))
                return "NaN";

            // Translate the double into sign, exponent and mantissa.
            long bits = BitConverter.DoubleToInt64Bits(d);
            // Note that the shift is sign-extended, hence the test against -1 not 1
            bool negative = (bits < 0);
            int exponent = (int)((bits >> 52) & 0x7ffL);
            long mantissa = bits & 0xfffffffffffffL;

            // Subnormal numbers; exponent is effectively one higher,
            // but there's no extra normalisation bit in the mantissa
            if (exponent == 0)
            {
                exponent++;
            }
            // Normal numbers; leave exponent as it is but add extra
            // bit to the front of the mantissa
            else
            {
                mantissa = mantissa | (1L << 52);
            }

            // Bias the exponent. It's actually biased by 1023, but we're
            // treating the mantissa as m.0 rather than 0.m, so we need
            // to subtract another 52 from it.
            exponent -= 1075;

            if (mantissa == 0)
            {
                return "0";
            }

            /* Normalize */
            while ((mantissa & 1) == 0)
            {    /*  i.e., Mantissa is even */
                mantissa >>= 1;
                exponent++;
            }

            /// Construct a new decimal expansion with the mantissa
            ArbitraryDecimal ad = new ArbitraryDecimal(mantissa);

            // If the exponent is less than 0, we need to repeatedly
            // divide by 2 - which is the equivalent of multiplying
            // by 5 and dividing by 10.
            if (exponent < 0)
            {
                for (int i = 0; i < -exponent; i++)
                    ad.MultiplyBy(5);
                ad.Shift(-exponent);
            }
            // Otherwise, we need to repeatedly multiply by 2
            else
            {
                for (int i = 0; i < exponent; i++)
                    ad.MultiplyBy(2);
            }

            // Finally, return the string with an appropriate sign
            if (negative)
                return "-" + ad.ToString();
            else
                return ad.ToString();
        }

        /// <summary>Private class used for manipulating
        class ArbitraryDecimal
        {
            /// <summary>Digits in the decimal expansion, one byte per digit
            byte[] digits;
            /// <summary> 
            /// How many digits are *after* the decimal point
            /// </summary>
            int decimalPoint = 0;

            /// <summary> 
            /// Constructs an arbitrary decimal expansion from the given long.
            /// The long must not be negative.
            /// </summary>
            internal ArbitraryDecimal(long x)
            {
                string tmp = x.ToString(CultureInfo.InvariantCulture);
                digits = new byte[tmp.Length];
                for (int i = 0; i < tmp.Length; i++)
                    digits[i] = (byte)(tmp[i] - '0');
                Normalize();
            }

            /// <summary>
            /// Multiplies the current expansion by the given amount, which should
            /// only be 2 or 5.
            /// </summary>
            internal void MultiplyBy(int amount)
            {
                byte[] result = new byte[digits.Length + 1];
                for (int i = digits.Length - 1; i >= 0; i--)
                {
                    int resultDigit = digits[i] * amount + result[i + 1];
                    result[i] = (byte)(resultDigit / 10);
                    result[i + 1] = (byte)(resultDigit % 10);
                }
                if (result[0] != 0)
                {
                    digits = result;
                }
                else
                {
                    Array.Copy(result, 1, digits, 0, digits.Length);
                }
                Normalize();
            }

            /// <summary>
            /// Shifts the decimal point; a negative value makes
            /// the decimal expansion bigger (as fewer digits come after the
            /// decimal place) and a positive value makes the decimal
            /// expansion smaller.
            /// </summary>
            internal void Shift(int amount)
            {
                decimalPoint += amount;
            }

            /// <summary>
            /// Removes leading/trailing zeroes from the expansion.
            /// </summary>
            internal void Normalize()
            {
                int first;
                for (first = 0; first < digits.Length; first++)
                    if (digits[first] != 0)
                        break;
                int last;
                for (last = digits.Length - 1; last >= 0; last--)
                    if (digits[last] != 0)
                        break;

                if (first == 0 && last == digits.Length - 1)
                    return;

                byte[] tmp = new byte[last - first + 1];
                for (int i = 0; i < tmp.Length; i++)
                    tmp[i] = digits[i + first];

                decimalPoint -= digits.Length - (last + 1);
                digits = tmp;
            }

            /// <summary>
            /// Converts the value to a proper decimal string representation.
            /// </summary>
            public override String ToString()
            {
                char[] digitString = new char[digits.Length];
                for (int i = 0; i < digits.Length; i++)
                    digitString[i] = (char)(digits[i] + '0');

                // Simplest case - nothing after the decimal point,
                // and last real digit is non-zero, eg value=35
                if (decimalPoint == 0)
                {
                    return new string(digitString);
                }

                // Fairly simple case - nothing after the decimal
                // point, but some 0s to add, eg value=350
                if (decimalPoint < 0)
                {
                    return new string(digitString) +
                           new string('0', -decimalPoint);
                }

                // Nothing before the decimal point, eg 0.035
                if (decimalPoint >= digitString.Length)
                {
                    return "0." +
                        new string('0', (decimalPoint - digitString.Length)) +
                        new string(digitString);
                }

                // Most complicated case - part of the string comes
                // before the decimal point, part comes after it,
                // eg 3.5
                return new string(digitString, 0,
                                   digitString.Length - decimalPoint) +
                    "." +
                    new string(digitString,
                                digitString.Length - decimalPoint,
                                decimalPoint);
            }
        }
    }
    /// <summary>
    /// /////////////
    /// </summary>
    public class DigitCount
    {
        public int Get(sbyte num)
        {
            if(num < 0)
            {
                sbyte buff = num;
                num = (sbyte)~buff;
                num += 1;
            }
            int count = 0;
            while (num > 0)
            {
                if ((num & 1) == 1)//(!(num & 1))
                {
                    count++;
                }
                num >>= 1;
            }
            return count;
        }
        //public static int operator &(DigitCount a, float b)
        //{

        //    return 0;
        //}
        public int Get(float num)
        {
            //if (float.IsPositiveInfinity(num))
            //    return "+Infinity";
            //if (float.IsNegativeInfinity(num))
            //    return "-Infinity";
            //if (float.IsNaN(num))
            //    return "NaN";

            int count = 0;
            int numInt = (int)num ;
            float numFract = num - numInt;
            //
            while (numInt > 0)
            {
                if ((numInt & 1) == 1)//(!(num & 1))
                {
                    count++;
                }
                numInt >>= 1;
            }
            //
            while (numFract != 0 && numFract != 1)
            {
                numFract *= 2;
                if (numFract > 1)
                {
                    count++;
                    numFract -= 1;
                }
            }
            if (numFract == 1)
                count++;
            //
            return count;
        }
    }
    class Program
    {
        static int ToBinary1(int num)
        {
            List<int> arr = new List<int>();
            int temp = 0;            
            while (num > 0)
            {
                arr.Add(num % 2);
                num /= 2;
            }
            foreach(var i in arr)
            {
                if(i == 1)
                {
                    temp++;
                }
            }
            return temp;
        }
        static int ToBinary2(int num)
        {
            int count = 0;
            while (num > 0)
            {
                int res = num % 2;
                if(res == 1)
                {
                    count++;
                }
                num /= 2;
            }
            return count;
        }
        static int ToBinary3(int num)
        {
            int mask = 128;//10000000
            int count = 0;
            while (mask > 0)
            {
                int res = num % 2;
                if ((num & mask) == 0)
                { }
                //Console.Write("0") ;
                else
                {
                    //Console.Write("1");
                    count++;
                }
                mask = mask >> 1;//right shift
            }
            //Console.WriteLine($"\n{ count}");
            return count;
        }
        static int ToBinary4(int num)
        {
            int count = 0;
            while (num > 0)
            {
                if ((num & 1) == 1)//(!(num & 1))
                {
                    count++;
                }
                num >>= 1;
            }
            return count;
        }
        static int ToBinary5(float num)
        {
            int count = 0;
            while (num != 0 && num != 1)
            {
                num *= 2;
                if (num > 1)
                {
                    count++;
                    num -= 1;
                }
            }
            if (num == 1)
                count++;
            return count;
        }
        static bool isNearlyEqualZero(float num)
        {
            const float epsilonZ = 1e-6f;
            return num <= epsilonZ;
        }
        static bool isNearlyEqualInfinity(float num)
        {
            const float epsilonInf = 1.5e30f;
            return (num >= -epsilonInf) || (num <= epsilonInf);
        }
        static int ToBinary6(float num)
        {
            if (isNearlyEqualZero(num))//float.IsNaN(num)
            {
                throw new DivideByZeroException("Infinity!");
            }
            if (isNearlyEqualInfinity(num))//float.IsInfinity(num)
            {
                //
            }
            int count = 0;
            int numInt = (int)num;
            float numFract = num - numInt;
            //
            while (numInt > 0)
            {
                if ((numInt & 1) == 1)//(!(num & 1))
                {
                    count++;
                }
                numInt >>= 1;
            }
            //
            while (numFract != 0 && numFract != 1)
            {
                numFract *= 2;
                if (numFract > 1)
                {
                    count++;
                    numFract -= 1;
                }
            }
            if (numFract == 1)
                count++;
            //
            return count;
        }
        static string ToBinaryString(float value)
        {

            int bitCount = sizeof(float) * 8; // never rely on your knowledge of the size
            char[] result = new char[bitCount]; // better not use string, to avoid ineffective string concatenation repeated in a loop

            // now, most important thing: (int)value would be "semantic" cast of the same
            // mathematical value (with possible rounding), something we don't want; so:
            int intValue = System.BitConverter.ToInt32(BitConverter.GetBytes(value), 0);

            for (int bit = 0; bit < bitCount; ++bit)
            {
                int maskedValue = intValue & (1 << bit); // this is how shift and mask is done.
                if (maskedValue > 0)
                    maskedValue = 1;
                // at this point, masked value is either int 0 or 1
                result[bitCount - bit - 1] = maskedValue.ToString()[0]; // bits go right-to-left in usual Western Arabic-based notation
            }

            return new string(result); // string from character array
        }
        static void Main(string[] args)
        {
            Console.WriteLine(ToBinary4(23));
            Console.WriteLine(ToBinary6(23));
        }

        
    }
    
}
