/*
 *  Copyright (c) 2017 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#ifndef API_AUDIO_CODECS_ISAC_AUDIO_DECODER_ISAC_FLOAT_H_
#define API_AUDIO_CODECS_ISAC_AUDIO_DECODER_ISAC_FLOAT_H_

#include <memory>
#include <vector>

#include "absl/types/optional.h"
#include "api/audio_codecs/audio_codec_pair_id.h"
#include "api/audio_codecs/audio_decoder.h"
#include "api/audio_codecs/audio_format.h"
#include "api/webrtc_key_value_config.h"
#include "rtc_base/system/rtc_export.h"

namespace webrtc {

// iSAC decoder API (floating-point implementation) for use as a template
// parameter to CreateAudioDecoderFactory<...>().
struct RTC_EXPORT AudioDecoderIsacFloat {
  struct Config {
    bool IsOk() const {
      return sample_rate_hz == 16000 || sample_rate_hz == 32000;
    }
    int sample_rate_hz = 16000;
  };
  static absl::optional<Config> SdpToConfig(const SdpAudioFormat& audio_format);
  static void AppendSupportedDecoders(std::vector<AudioCodecSpec>* specs);
  static std::unique_ptr<AudioDecoder> MakeAudioDecoder(
      Config config,
      absl::optional<AudioCodecPairId> codec_pair_id = absl::nullopt,
      const WebRtcKeyValueConfig* field_trials = nullptr);
};

}  // namespace webrtc

#endif  // API_AUDIO_CODECS_ISAC_AUDIO_DECODER_ISAC_FLOAT_H_
