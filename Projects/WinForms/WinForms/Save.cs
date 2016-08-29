using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Json;
using System.Drawing;
using System.IO;
using System.Drawing.Imaging;

namespace WinForms
{
    [DataContract]
    class Save // Used to serialize data
    {        
        public Bitmap tileSet;

        public Bitmap background;

        [DataMember(Name = "background", IsRequired = true)]
        public byte[] tileSetByte;

        [DataMember(Name = "tileSet", IsRequired = true)]
        public byte[] backgroundByte;           

        [DataMember(Name = "mapData", IsRequired = true)]
        public TileLayer map;

        [DataMember(Name = "gridColumns", IsRequired = true)]
        public int gridColumns;

        [DataMember(Name = "gridRows", IsRequired = true)]
        public int gridRows;

        [DataMember(Name = "tileHeight", IsRequired = true)]
        public int tileHeight;

        [DataMember(Name = "tileWidth", IsRequired = true)]
        public int tileWidth;

        [DataMember(Name = "gridHeight", IsRequired = true)]
        public int gridHeight;

        [DataMember(Name = "gridWidth", IsRequired = true)]
        public int gridWidth;

        public void saveData(Bitmap tileSet, Bitmap background, TileLayer map, int gridColumns, int gridRows, int gridHeight, int gridWidth, int tileHeight, int tileWidth)
        {
            this.tileSet = tileSet;

            this.background = background;

            this.tileSetByte = BitmapToByte(this.tileSet);

            this.backgroundByte = BitmapToByte(this.background);

            this.map = map;

            this.gridColumns = gridColumns;

            this.gridRows = gridRows;

            this.gridHeight = gridHeight;

            this.gridWidth = gridWidth;

            this.tileHeight = tileHeight;

            this.tileWidth = tileWidth;
        }

        public static byte[] BitmapToByte(Bitmap bitmap)
        {
            using (MemoryStream ms = new MemoryStream())
            {
                bitmap.Save(ms, ImageFormat.Png);
                return ms.ToArray();
            }
        }

        public static Bitmap ByteToBitmap(byte[] stream)
        {
            using (var ms = new MemoryStream(stream))
            {
                return new Bitmap(ms);
            }
        }
    }


}
