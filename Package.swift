// swift-tools-version: 5.9
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "FaceDetectorLibrary_iOS",
    defaultLocalization: "pt",
    products: [
        // Products define the executables and libraries a package produces, making them visible to other packages.
        .library(
            name: "FaceDetectorLibrary_iOS",
            targets: ["MediaPipeTasksVision"]),
    ],
    targets: [
        .target(name: "FaceDetectorLibrary_iOS",
                dependencies: ["MediaPipeTasksVision"]),
        .binaryTarget(
            name: "MediaPipeTasksVision",
            path: "MediaPipeTasksVision.xcframework")
    ]
)
