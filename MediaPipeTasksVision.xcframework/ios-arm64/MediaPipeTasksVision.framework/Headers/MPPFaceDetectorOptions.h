// Copyright 2023 The MediaPipe Authors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#import <Foundation/Foundation.h>

#import "MPPTaskOptions.h"
#import "MPPRunningMode.h"
#import "MPPFaceDetectorResult.h"

NS_ASSUME_NONNULL_BEGIN

@class MPPFaceDetector;

/**
 * This protocol defines an interface for the delegates of `MPPFaceDetector` face to receive
 * results of performing asynchronous face detection on images (i.e, when `runningMode` =
 * `MPPRunningModeLiveStream`).
 *
 * The delegate of `MPPFaceDetector` must adopt `MPPFaceDetectorLiveStreamDelegate` protocol.
 * The methods in this protocol are optional.
 */
NS_SWIFT_NAME(FaceDetectorLiveStreamDelegate)
@protocol MPPFaceDetectorLiveStreamDelegate <NSObject>

@optional

/**
 * This method notifies a delegate that the results of asynchronous face detection of
 * an image submitted to the `MPPFaceDetector` is available.
 *
 * This method is called on a private serial dispatch queue created by the `MPPFaceDetector`
 * for performing the asynchronous delegates calls.
 *
 * @param faceDetector The face detector which performed the face detection.
 * This is useful to test equality when there are multiple instances of `MPPFaceDetector`.
 * @param result The `MPPFaceDetectorResult` object that contains a list of detections, each
 * detection has a bounding box that is expressed in the unrotated input frame of reference
 * coordinates system, i.e. in `[0,image_width) x [0,image_height)`, which are the dimensions of the
 * underlying image data.
 * @param timestampInMilliseconds The timestamp (in milliseconds) which indicates when the input
 * image was sent to the face detector.
 * @param error An optional error parameter populated when there is an error in performing face
 * detection on the input live stream image data.
 */
- (void)faceDetector:(MPPFaceDetector *)faceDetector
    didFinishDetectionWithResult:(nullable MPPFaceDetectorResult *)result
         timestampInMilliseconds:(NSInteger)timestampInMilliseconds
                           error:(nullable NSError *)error
    NS_SWIFT_NAME(faceDetector(_:didFinishDetection:timestampInMilliseconds:error:));
@end

/** Options for setting up a `MPPFaceDetector`. */
NS_SWIFT_NAME(FaceDetectorOptions)
@interface MPPFaceDetectorOptions : MPPTaskOptions <NSCopying>

/**
 * Running mode of the face detector task. Defaults to `MPPRunningModeImage`.
 * `MPPFaceDetector` can be created with one of the following running modes:
 *  1. `MPPRunningModeImage`: The mode for performing face detection on single image inputs.
 *  2. `MPPRunningModeVideo`: The mode for performing face detection on the decoded frames of a
 *      video.
 *  3. `MPPRunningModeLiveStream`: The mode for performing face detection on a live stream of
 *      input data, such as from the camera.
 */
@property(nonatomic) MPPRunningMode runningMode;

/**
 * An object that confirms to `MPPFaceDetectorLiveStreamDelegate` protocol. This object must
 * implement `faceDetector:didFinishDetectionWithResult:timestampInMilliseconds:error:` to receive
 * the results of performing asynchronous face detection on images (i.e, when `runningMode` =
 * `MPPRunningModeLiveStream`).
 */
@property(nonatomic, weak, nullable) id<MPPFaceDetectorLiveStreamDelegate>
    faceDetectorLiveStreamDelegate;

/**
 * The minimum confidence score for the face detection to be considered successful. Defaults to
 * 0.5.
 */
@property(nonatomic) float minDetectionConfidence;

/**
 * The minimum non-maximum-suppression threshold for face detection to be considered overlapped.
 * Defaults to 0.3.
 */
@property(nonatomic) float minSuppressionThreshold;

@end

NS_ASSUME_NONNULL_END
