#pragma once

#include <ATen/ATen.h>

namespace torch {
namespace fft {

/// Computes the 1 dimensional fast Fourier transform over a given dimension.
/// See https://pytorch.org/docs/master/fft.html#torch.fft.fft.
///
/// Example:
/// ```
/// auto t = torch::randn(128, dtype=kComplexDouble);
/// torch::fft::fft(t);
/// ```
inline Tensor fft(const Tensor& self,
                  c10::optional<int64_t> n=c10::nullopt,
                  int64_t dim=-1,
                  c10::optional<std::string> norm=c10::nullopt) {
  return torch::fft_fft(self, n, dim, norm);
}

/// Computes the 1 dimensional inverse Fourier transform over a given dimension.
/// See https://pytorch.org/docs/master/fft.html#torch.fft.ifft.
///
/// Example:
/// ```
/// auto t = torch::randn(128, dtype=kComplexDouble);
/// torch::fft::ifft(t);
/// ```
inline Tensor ifft(const Tensor& self,
                  c10::optional<int64_t> n=c10::nullopt,
                  int64_t dim=-1,
                  c10::optional<std::string> norm=c10::nullopt) {
  return torch::fft_ifft(self, n, dim, norm);
}

/// Computes the 1 dimensional FFT of real input with onesided Hermitian output.
/// See https://pytorch.org/docs/master/fft.html#torch.fft.rfft.
///
/// Example:
/// ```
/// auto t = torch::randn(128);
/// auto T = torch::fft::rfft(t);
/// assert(T.is_complex() && T.numel() == 128 / 2 + 1);
/// ```
inline Tensor rfft(const Tensor& self,
                  c10::optional<int64_t> n=c10::nullopt,
                  int64_t dim=-1,
                  c10::optional<std::string> norm=c10::nullopt) {
  return torch::fft_rfft(self, n, dim, norm);
}

/// Computes the inverse of torch.fft.rfft
///
/// The input is a onesided Hermitian Fourier domain signal, with real-valued
/// output. See https://pytorch.org/docs/master/fft.html#torch.fft.irfft
///
/// Example:
/// ```
/// auto T = torch::randn(128 / 2 + 1, torch::kComplexDouble);
/// auto t = torch::fft::irfft(t, /*n=*/128);
/// assert(t.is_floating_point() && T.numel() == 128);
/// ```
inline Tensor irfft(const Tensor& self,
                    c10::optional<int64_t> n=c10::nullopt,
                    int64_t dim=-1,
                    c10::optional<std::string> norm=c10::nullopt) {
  return torch::fft_irfft(self, n, dim, norm);
}

/// Computes the 1 dimensional FFT of a onesided Hermitian signal
///
/// The input represents a Hermitian symmetric time domain signal. The returned
/// Fourier domain representation of such a signal is a real-valued. See
/// https://pytorch.org/docs/master/fft.html#torch.fft.hfft
///
/// Example:
/// ```
/// auto t = torch::randn(128 / 2 + 1, torch::kComplexDouble);
/// auto T = torch::fft::hfft(t, /*n=*/128);
/// assert(T.is_floating_point() && T.numel() == 128);
/// ```
inline Tensor hfft(const Tensor& self,
                   c10::optional<int64_t> n=c10::nullopt,
                   int64_t dim=-1,
                   c10::optional<std::string> norm=c10::nullopt) {
  return torch::fft_hfft(self, n, dim, norm);
}

/// Computes the inverse FFT of a real-valued Fourier domain signal.
///
/// The output is a onesided representation of the Hermitian symmetric time
/// domain signal. See https://pytorch.org/docs/master/fft.html#torch.fft.ihfft.
///
/// Example:
/// ```
/// auto T = torch::randn(128, torch::kDouble);
/// auto t = torch::fft::ihfft(t);
/// assert(t.is_complex() && T.numel() == 128 / 2 + 1);
/// ```
inline Tensor ihfft(const Tensor& self,
                    c10::optional<int64_t> n=c10::nullopt,
                    int64_t dim=-1,
                    c10::optional<std::string> norm=c10::nullopt) {
  return torch::fft_ihfft(self, n, dim, norm);
}

}} // torch::fft
