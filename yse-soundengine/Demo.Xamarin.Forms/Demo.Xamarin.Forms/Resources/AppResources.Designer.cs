﻿//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//     Runtime Version:4.0.30319.42000
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

namespace Demo.Xamarin.Forms.Resources {
    using System;
    
    
    /// <summary>
    ///   A strongly-typed resource class, for looking up localized strings, etc.
    /// </summary>
    // This class was auto-generated by the StronglyTypedResourceBuilder
    // class via a tool like ResGen or Visual Studio.
    // To add or remove a member, edit your .ResX file then rerun ResGen
    // with the /str option, or rebuild your VS project.
    [global::System.CodeDom.Compiler.GeneratedCodeAttribute("System.Resources.Tools.StronglyTypedResourceBuilder", "15.0.0.0")]
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
    [global::System.Runtime.CompilerServices.CompilerGeneratedAttribute()]
    internal class AppResources {
        
        private static global::System.Resources.ResourceManager resourceMan;
        
        private static global::System.Globalization.CultureInfo resourceCulture;
        
        [global::System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1811:AvoidUncalledPrivateCode")]
        internal AppResources() {
        }
        
        /// <summary>
        ///   Returns the cached ResourceManager instance used by this class.
        /// </summary>
        [global::System.ComponentModel.EditorBrowsableAttribute(global::System.ComponentModel.EditorBrowsableState.Advanced)]
        internal static global::System.Resources.ResourceManager ResourceManager {
            get {
                if (object.ReferenceEquals(resourceMan, null)) {
                    global::System.Resources.ResourceManager temp = new global::System.Resources.ResourceManager("Demo.Xamarin.Forms.Resources.AppResources", typeof(AppResources).Assembly);
                    resourceMan = temp;
                }
                return resourceMan;
            }
        }
        
        /// <summary>
        ///   Overrides the current thread's CurrentUICulture property for all
        ///   resource lookups using this strongly typed resource class.
        /// </summary>
        [global::System.ComponentModel.EditorBrowsableAttribute(global::System.ComponentModel.EditorBrowsableState.Advanced)]
        internal static global::System.Globalization.CultureInfo Culture {
            get {
                return resourceCulture;
            }
            set {
                resourceCulture = value;
            }
        }
        
        /// <summary>
        ///   Looks up a localized string similar to This Demo shows how YSE Handles 3D. The green circle symbolizes the listener, the blue circles symbolize sounds. All of them can be moved. This demo is best listened to with headphones..
        /// </summary>
        internal static string Basics3DInfo {
            get {
                return ResourceManager.GetString("Basics3DInfo", resourceCulture);
            }
        }
        
        /// <summary>
        ///   Looks up a localized string similar to Toggle Audio Test.
        /// </summary>
        internal static string BasicsAudioTestCheckbox {
            get {
                return ResourceManager.GetString("BasicsAudioTestCheckbox", resourceCulture);
            }
        }
        
        /// <summary>
        ///   Looks up a localized string similar to YSE has an integrated audio test to make sure the basics are working. With just one line of code it can be turned on and off..
        /// </summary>
        internal static string BasicsAudioTestIntro {
            get {
                return ResourceManager.GetString("BasicsAudioTestIntro", resourceCulture);
            }
        }
        
        /// <summary>
        ///   Looks up a localized string similar to Sounds can be assigned to channels. In addition to a volume control, effects such as reverb can be assigned to a channel. Also, every channel has its own rendering thread. Using multiple channels can speed up audio calculations..
        /// </summary>
        internal static string BasicsChannelsInfo {
            get {
                return ResourceManager.GetString("BasicsChannelsInfo", resourceCulture);
            }
        }
        
        /// <summary>
        ///   Looks up a localized string similar to This example shows trivial sound interactions while playing from a sound file. (Accessing sound files on Android is not trivial, but we&apos;re working on that.).
        /// </summary>
        internal static string BasicsPlaySoundInfo {
            get {
                return ResourceManager.GetString("BasicsPlaySoundInfo", resourceCulture);
            }
        }
        
        /// <summary>
        ///   Looks up a localized string similar to A global reverb can be applied. There are several presets, but every parameter can also be set directly. Positional reverb for 2D/3D is also possible..
        /// </summary>
        internal static string BasicsReverbInfo {
            get {
                return ResourceManager.GetString("BasicsReverbInfo", resourceCulture);
            }
        }
    }
}
