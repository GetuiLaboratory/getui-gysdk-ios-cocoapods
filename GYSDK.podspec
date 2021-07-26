Pod::Spec.new do |s|

  s.name         = "GYSDK"
  s.version      = "2.0.8.0"
  s.summary      = "个验 iOS SDK CocoaPods 集成库"

  s.homepage     = "https://docs.getui.com/geyan/"
  # s.screenshots  = "www.example.com/screenshots_1.gif", "www.example.com/screenshots_2.gif"



  s.license      = "MIT"
  # s.license      = { :type => "MIT", :file => "FILE_LICENSE" }

  s.author       = { "个推" => "support@getui.com" }

  s.platform     = :ios, "9.0"

  s.ios.deployment_target = "9.0"

  s.source       = { :git => "https://github.com/GetuiLaboratory/getui-gysdk-ios-cocoapods.git", :tag => "#{s.version}" }

  # 依赖的第三方pod
  s.dependency 'GTCommonSDK'

  # 使用了第三方静态库
  # s.ios.vendored_libraries = 'libxxx.a'
  s.ios.vendored_frameworks = 'GeYanSdk.framework'

  s.frameworks = "AdSupport"

  s.libraries = 'z','c++'

  s.requires_arc = true
  s.static_framework = true


end
