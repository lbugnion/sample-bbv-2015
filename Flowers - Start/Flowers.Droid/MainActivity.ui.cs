using Android.Widget;
using Flowers.Helpers;

namespace Flowers
{
    public partial class MainActivity : ActivityBaseEx
    {
        private ListView _flowersList;
        private TextView _lastLoadedText;

        public ListView FlowersList
        {
            get
            {
                return _flowersList
                       ?? (_flowersList = FindViewById<ListView>(Resource.Id.FlowersList));
            }
        }

        public TextView LastLoadedText
        {
            get
            {
                return _lastLoadedText
                       ?? (_lastLoadedText = FindViewById<TextView>(Resource.Id.LastLoadedText));
            }
        }
    }
}