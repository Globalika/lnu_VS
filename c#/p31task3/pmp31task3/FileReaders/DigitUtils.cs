using System.Text.RegularExpressions;

namespace p31task3
{
    public class DigitUtils
    {
        readonly private string filePath =
            System.IO.Path.GetFullPath(@"..\..\files\file1.txt");
        private FileUtils fileUtils;
        private Regex regex;
        private readonly string patern = @" +[0-9]{1} +";
        public DigitUtils()
        {
            fileUtils = new FileUtils();
            regex = new Regex(patern);
        }
        public List<int> getNumbers(string path)
        {
            var list = fileUtils.ReadItemsFromFile(path);
            List<int> result = new List<int>();
            foreach (var line in list)
            {
                foreach (Match match in regex.Matches(line))
                {
                    result.Add(int.Parse(match.Value.Trim(' ')));
                }
            }
            return result;
        }

    }
}
