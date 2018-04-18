
Pod::Spec.new do |s|

s.name         = "CycleAlertView"
s.version      = "1.0.0"
s.summary      = "CycleAlertAnyView can do whose people like to alert any content,but not have customView to alert and relize their dream."
s.homepage     = "https://github.com/cqcycle/CycleAlertAnyView.git"
s.license      = "MIT"
s.author       = { "zhoubo" => "15696564260@163.com" }
s.platform     = :ios, "8.0"
s.source       = { :git => "https://github.com/cqcycle/CycleAlertAnyView.git", :tag => s.version.to_s }

s.source_files  = "CycleAlertView", "CycleAlertView/**/*.{h,m}"
s.public_header_files = "CycleAlertView/**/*.h"
# s.frameworks = "UIKit", "Foundation"
s.requires_arc = true

end
