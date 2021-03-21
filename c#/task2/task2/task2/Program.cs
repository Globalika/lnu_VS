using HDF.PInvoke;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Threading;

using static HDF.PInvoke.H5T;
using hid_t = System.Int32;


namespace task2
{
    
    class Program
    {
        static string filePath = @"C:\Users\volod\source\Lnu_VS\c#\task2\task2\file\matrix.txt";
        static readonly char delim = ' ';
        static int[,] GetMatrixFromFile()
        {
            int[,] matrix;
            using (var streamReader = new StreamReader(filePath))
            {
                string fileLine;
                int length = int.Parse(streamReader.ReadLine());
                matrix = new int[length, length];
                for (int i = 0; i < length; i++)
                {
                    fileLine = streamReader.ReadLine();
                    string[] strObjItems = fileLine.Split(delim);
                    for (int j = 0; j < length; j++)
                    {
                        matrix[i, j] = int.Parse(strObjItems[j]);
                    }
                }
            }
            return matrix;
        }
        static int[][] TransformMatrixToJaggedOne(int[,] matrix)
        {
            int dimens = matrix.Rank + 1;
            int[][] jaggedMatrix = new int[dimens][];
            for(int k = 0; k < dimens; k++)
            {
                jaggedMatrix[k] = new int[dimens];
            }
            for (int i = 0; i < dimens; i++)
            {
                for (int j = 0; j < dimens; j++)
                {
                    jaggedMatrix[i][j] = matrix[i,j];
                    //jaggedMatrix[i].Append<int>(matrix[i, j]);// = matrix[i,j];
                }
            }
            return jaggedMatrix;
        }
        static void PrintMatrix(int[,] matrix)
        {
            for (int i = 0; i <= matrix.Rank; i++)
            {
                for (int j = 0; j <= matrix.Rank; j++)
                {
                    Console.Write($"{matrix[i, j]} ");
                }
                Console.WriteLine();
            }
        }
        static void PrintJaggedMatrix(int[][] matrix)
        {
            for (int i = 0; i < matrix.Length; i++)
            {
                for (int j = 0; j < matrix[i].Length; j++)
                {
                    Console.Write($"{matrix[i][j]} ");
                }
                Console.WriteLine();
            }
        }
        static int[,] MultiplyMatrixies(int[,] matrix1, int[,] matrix2)
        {
            Stopwatch stopWatch = new Stopwatch();
            stopWatch.Start();
            //Thread.Sleep(10000);
            int dimens = Convert.ToInt32(Math.Sqrt((matrix1.Length)));
            int[,] resultMatrix = new int[dimens, dimens];
            for (int i = 0; i < dimens; i++)
            {
                for (int j = 0; j < dimens; j++)
                {
                    resultMatrix[i, j] = 0;
                    for (int k = 0; k < dimens; k++)
                    {
                        resultMatrix[i, j] += matrix1[i, k] * matrix2[k, j];
                    }
                }
            }
            stopWatch.Stop();
            Console.WriteLine($"Default multiply time: {stopWatch.Elapsed}");
            return resultMatrix;
        }
        static int[][] MultiplyJaggedMatrixies(int[][] matrix1, int[][] matrix2)
        {
            Stopwatch stopWatch = new Stopwatch();
            stopWatch.Start();
            int dimens = matrix1.Length;
            int[][] resultMatrix = new int[dimens][];
            for(int d = 0; d < dimens; d++)
            {
                resultMatrix[d] = new int[dimens];
            }

            for (int i = 0; i < dimens; i++)
            {
                for (int j = 0; j < dimens; j++)
                {
                    resultMatrix[i][j] = 0;
                    for (int k = 0; k < dimens; k++)
                    {
                        resultMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
                    }
                }
            }
            stopWatch.Stop();
            Console.WriteLine($"Jagged multiply time: {stopWatch.Elapsed}");
            return resultMatrix;
        }


        private bool ReadStringArray(hid_t fileId, string datasetPath, int recordLength, out string[] datasetOut)
        {
            datasetOut = null;
            List<string> dataset = new List<string>();

            hid_t dataSetId = 0;
            hid_t dataSpaceId = 0;
            hid_t typeId = 0;

            try
            {
                dataSetId = (int)H5D.open(fileId, datasetPath);
                dataSpaceId = (int)H5D.get_space(dataSetId);
                typeId = (int)H5T.copy(H5T.C_S1);
                H5T.set_size(typeId, new IntPtr(recordLength));

                int rank = H5S.get_simple_extent_ndims(dataSpaceId);
                ulong[] dims = new ulong[rank];
                ulong[] maxDims = new ulong[rank];
                H5S.get_simple_extent_dims(dataSpaceId, dims, maxDims);
                byte[] dataBytes = new byte[dims[0] * (ulong)recordLength];

                GCHandle pinnedArray = GCHandle.Alloc(dataBytes, GCHandleType.Pinned);
                H5D.read(dataSetId, typeId, H5S.ALL, H5S.ALL, H5P.DEFAULT, pinnedArray.AddrOfPinnedObject());
                pinnedArray.Free();

                for (int i = 0; i < (int)(dims[0]); i++)
                {
                    byte[] slice = dataBytes.Skip<byte>(i * recordLength).Take<byte>(recordLength).ToArray<byte>();
                    var content = System.Text.Encoding.ASCII.GetString(slice).Trim();
                    dataset.Add(content);
                }
            }
            catch (Exception ex)
            {
                return false;
            }
            finally
            {
                if (typeId != 0) H5T.close(typeId);
                if (dataSpaceId != 0) H5S.close(dataSpaceId);
                if (dataSetId != 0) H5D.close(dataSetId);
            }

            datasetOut = dataset.ToArray();

            return true;
        }

        static void Main(string[] args)
        {
            Console.WriteLine();
            int[,] matriX = GetMatrixFromFile();
            PrintMatrix(matriX);
            Console.WriteLine();
            Console.WriteLine();
            int[][] jaggedMatriX = TransformMatrixToJaggedOne(matriX);
            PrintJaggedMatrix(jaggedMatriX);
            Console.WriteLine();
            int[,] resultByMultiplyMatrix = MultiplyMatrixies(matriX, matriX);
            PrintMatrix(resultByMultiplyMatrix);
            Console.WriteLine();
            Console.WriteLine();
            int[][] resultByMultiplyJaggedMatrix = MultiplyJaggedMatrixies(jaggedMatriX, jaggedMatriX);
            PrintJaggedMatrix(resultByMultiplyJaggedMatrix);
            Console.WriteLine();
            //
            long type_id;
            type_id = H5T.create('', 4);

            //
            Console.ReadLine();
        }
    }
}