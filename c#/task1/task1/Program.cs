using System;

namespace task1
{
    public class Binary
    {
        public static string GetSByteBinaryString(sbyte number)
        {
            if(number < 0)
            {
                sbyte buff = Convert.ToSByte(~number);
                number = Convert.ToSByte(buff + 1);
            }
            char[] str = new char[8];
            int pos = 7;
            for (int i = 0; i < 8; i++)
            {
                if ((number & ((sbyte)1 << i)) != 0)
                {
                    str[pos] = '1';
                }
                else
                {
                    str[pos] = '0';
                }
                pos--;
            }
            return new string(str);
        }
        public static string GetSByteBinaryString(float number)
        {
            int numInt =  (int)number;
            float numFract = number - numInt;

            string result = GetIntegerPartBinaryString(numInt) + '.' + GetPartialPartBinaryString(numFract);

            Console.WriteLine($" Floating Point Standart : {GetFloatingPointStandart(result, number < 0)}");

            return result;
        }
        public static string GetIntegerPartBinaryString(int number)
        {
            //
            if (number < 0)
            {
                int buff = ~number;
                number = buff + 1;
            }
            //
            char[] str = new char[32];
            int pos = 31;
            for (int i = 0; i < 32; i++)
            {
                if ((number & ((sbyte)1 << i)) != 0)
                {
                    str[pos] = '1';
                }
                else
                {
                    str[pos] = '0';
                }
                pos--;
            }
            var strBuff = new string(str);
            var cleanedString = strBuff.Replace("\0", string.Empty);
            int zeroPos = 0;
            while (cleanedString[zeroPos] != '1')
                zeroPos++;
            cleanedString = cleanedString.Substring(zeroPos);
            return cleanedString;
        }
        public static string GetPartialPartBinaryString(float number)
        {
            //
            if (number < 0)
            {
                number = Math.Abs(number);
            }
            //
            char[] str = new char[32];
            int pos = 0;
            while (number != 0 && number != 1 && pos != 31)
            {
                number *= 2;
                if (number >= 1)
                {
                    str[pos] = '1';
                    number -= 1;
                }
                else
                {
                    str[pos] = '0';
                }
                pos++;
            }
            var strBuff = new string(str);
            var cleanedString = strBuff.Replace("\0", string.Empty);
            return cleanedString;
        }
        public static string GetFloatingPointStandart(string str, bool sign)
        {
            //
            byte dotPos = 0;
            while (str[dotPos] != '.')
                dotPos++;
            //
            byte exponent = 127;
            exponent += Convert.ToByte(dotPos - 1);
            //
            string result = string.Empty;
            result += Convert.ToString(Convert.ToByte(sign)) + '.';
            //
            char[] exponentString = new char[8];
            int exponentPos = 7;
            for (int i = 0; i < 8; i++)
            {
                if ((exponent & ((byte)1 << i)) != 0)
                {
                    exponentString[exponentPos] = '1';
                }
                else
                {
                    exponentString[exponentPos] = '0';
                }
                exponentPos--;
            }
            var strBuff = new string(exponentString);
            var cleanedString = strBuff.Replace("\0", string.Empty);
            //
            result += cleanedString + '.';
            //
            str = str.Replace(".", string.Empty);
            string newStr = str.Substring(1, str.Length-1);
            if(newStr.Length > 23)
                newStr = newStr.Substring(22);
            result += newStr;
            int count = 23 - newStr.Length;
            while(count != 0)
            {
                result += '0';
                count--;
            }    
            //
            return result;
        }
        public static int CountNumericOne(string str)
        {
            int count = 0;
            for (int i = 0; i < str.Length; i++)
            {
                if (str[i] == '1')
                {
                    count++;
                }
            }
            return count;
        }

    }
    class Program
    {
        static void Main(string[] args)
        {

            Console.Write("Choose : 1 for SByte | 2 : for Float");
            int getch = Console.ReadKey(true).KeyChar-48;
            Console.WriteLine();
            if (getch == 1)
            {
                Console.Write(" Your SByte number : ");
                bool state = true;
                sbyte k = 0;
                

                while (state)
                {
                    try
                    {
                        k = Convert.ToSByte(Console.ReadLine());
                        state = false;
                        if (Single.IsInfinity(k))
                            throw new DivideByZeroException();
                        if (Single.IsNaN(k))
                            throw new Exception();
                        //k = 0;
                        //k /= 0;
                    }
                    catch (OverflowException ex)
                    {
                        Console.Write(ex.GetType() + " | " + "Try again ");
                        state = true;
                    }
                    catch (DivideByZeroException ex)
                    {
                        Console.Write(ex.GetType() + " | " + "Try again ");
                    }
                    catch (FormatException ex )
                    {
                        Console.Write(ex.GetType() + " | " + "Try again ");
                    }
                    catch (Exception ex)
                    {
                        Console.Write("NaN Exception" + " | " + "Try again ");
                    }
                }
                string str = Binary.GetSByteBinaryString(k);
                int n = Binary.CountNumericOne(str);
                Console.WriteLine($" Binary : {str}\n" +
                     $" Amount of 1`s : {n}");
            }
            else
            {
                Console.Write(" Your Float number : ");
                float k2 = Convert.ToSingle(Console.ReadLine());
                string str2 = Binary.GetSByteBinaryString(k2);
                int n2 = Binary.CountNumericOne(str2);
                Console.WriteLine($" Binary : {str2}\n" +
                     $" Amount of 1`s : {n2}");
            }
        }
    }
}