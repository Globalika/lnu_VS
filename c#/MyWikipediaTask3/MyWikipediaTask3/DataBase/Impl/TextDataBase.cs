using System;
using System.Collections.Generic;
using System.IO;

namespace MyWikipediaTask3.DataBase.Impl
{
    public class TextDataBase : BaseDataBase
    {

        static protected readonly char delim = ',';
        public override void UpdateTableContent(List<string[]> list, string tableName, string[] metaData)
        {
            using (StreamWriter streamWriter = new StreamWriter(CreateTablePath(tableName)))
            {
                streamWriter.WriteLine("#Table Start");
                string metaStr = string.Empty;
                for(int i = 0; i < metaData.Length;i++)
                {
                    if(!(i == metaData.Length-1))
                    {
                        metaStr += metaData[i] + delim;
                    }
                    else
                    {
                        metaStr += metaData[i];
                    }
                }
                streamWriter.WriteLine(metaStr);
                foreach (var it in list)
                {
                    string str = string.Empty;
                    for(int i = 0; i < it.Length; i++)
                    {
                        //Escaping characters
                        it[i] = it[i].Replace(@",", @",,");
                        //


                        if (!(i == it.Length - 1))
                        {
                            str += it[i] + delim;
                        }
                        else
                        {
                            str += it[i];
                        }
                    }
                    streamWriter.WriteLine(str);
                    //
                }
                streamWriter.WriteLine("#Table End");
            }
        }
        public override List<string[]> GetTableContent(string tableName)
        {
            List<string[]> list = new List<string[]>();
            string fileLine, metaLine;
            using (var streamReader = new StreamReader(CreateTablePath(tableName)))
            {
                if (streamReader.ReadLine() != "#Table Start")
                {
                    throw new Exception("Wrong Format");
                }
                else
                {
                    //
                    metaLine = streamReader.ReadLine();
                    //

                    //
                    while ((fileLine = streamReader.ReadLine()) != "#Table End")
                    {

                        //Escaping characters
                        fileLine = fileLine.Replace(@",,", @"|");
                        //


                        string[] strObjItems = fileLine.Split(delim);


                        ////Escaping characters
                        for (int i = 0; i < strObjItems.Length; i++)
                        {
                            strObjItems[i] = strObjItems[i].Replace(@"|", @",");
                        }
                        //
                        list.Add(strObjItems);
                    }
                }
            }
            return list;
        }

    }
}