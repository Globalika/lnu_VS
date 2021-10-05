using System;
using System.Windows;
using UserApp.ViewModels;

namespace UserApp.Views
{
    public partial class OptionsWindow : Window
    {
        public OptionsWindow(ref LogoViewModel logoViewModel)
        {
            InitializeComponent();
            DataContext = logoViewModel;
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            this.Height = Convert.ToDouble(LogoHeight.Text);
            this.Width = Convert.ToDouble(LogoWidth.Text);
            this.Close();
        }
    }
}
