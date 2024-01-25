// swift-tools-version: 5.9
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "FaceDetectorLibrary",
    platforms: [
            .iOS(.v15),
        ],
    products: [
        // Products define the executables and libraries a package produces, making them visible to other packages.
        .library(
            name: "FaceDetectorLibrary",
            targets: ["MediaPipeTasksVision"]),
    ],
    targets: [
        .target(name: "FaceDetectorLibrary",
                dependencies: ["MediaPipeTasksVision"]),
        .binaryTarget(
            name: "MediaPipeTasksVision",
            path: "MediaPipeTasksVision.xcframework")
    ]
)
