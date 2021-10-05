using System;
using System.ComponentModel;
using System.Runtime.CompilerServices;

namespace UserApp.Models
{
    public class Logo : INotifyPropertyChanged
    {
        public event PropertyChangedEventHandler PropertyChanged;
        public Logo(double logoHeight, double logoWidth, double logoAngle, string logoPath)
        {
            _height = logoHeight;
            _width = logoWidth;
            _angle = logoAngle;
            _path = logoPath;
        }
        private double _height;
        public double Height {
            get { return _height; }
            set
            {
                _height = value;
                OnPropertyChanged("Height");
            }
        }
        private double _width;
        public double Width
        {
            get { return _width; }
            set
            {
                _width = value;
                OnPropertyChanged("Width");
            }
        }
        private double _angle;
        public double Angle
        {
            get { return _angle; }
            set
            {
                _angle = value;
                OnPropertyChanged("Angle");
            }
        }
        private string _path = string.Empty;
        public string Path
        {
            get { return _path; }
        }
        protected void OnPropertyChanged([CallerMemberName] string name = null)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(name));
        }
    }
}
