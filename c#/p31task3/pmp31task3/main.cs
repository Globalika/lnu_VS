namespace p31task3
{
    class main
    {
        static void Main(string[] args)
        {
            string filePath =
                   System.IO.Path.GetFullPath(@"..\..\..\files\file1.txt");

            DigitUtils digit = new DigitUtils();

            var list = digit.getNumbers(filePath);

            foreach (var num in list)
            {
                Console.Write($"{num}\t");
            }

            Console.Read();
        }
    }
}
