namespace p31task3
{
    public class FileUtils
    {
        private string filePath;
        public List<string> fileLines;

        public FileUtils()
        {
            fileLines = new List<string>();
        }

        public List<string> ReadItemsFromFile(string path)
        {
            filePath = path;
            using (var streamReader = new StreamReader(filePath))
            {
                ReadItemsFromStream(streamReader);
            }
            return fileLines;
        }
        public void ReadItemsFromStream(StreamReader streamReader)
        {
            string fileLine;

            while ((fileLine = streamReader.ReadLine()) != null)
            {
                fileLines.Add(fileLine);
            }
        }
    }
}
