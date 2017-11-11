# Changelog

All notable changes to this project will be documented in this file, following semantic versioning.

## Unreleased

### Added

- Functions `pmatrix_linear_interpolation`/`matrix_linear_interpolation` for matrix linear interpolation.

## 0.2.0 - 2017-11-11

### Notes

If you are using any of the functions to generate an projection matrices, you should update to one of the newer version. The perspective matrices only chaged in name, but the orthographic matrices changed in implementation, fixing the top-down orientation, and requiring a near and far clipping.

### Added

- Link in the `README.md` to this CHANGELOG file.
- Functions `pmatrix_ortho`/`matrix_ortho` based on the old `pmatrix_ortho_zo`/`matrix_ortho_zo`.
- Functions `pmatrix_perspective`/`matrix_perspective` based on the old `pmatrix_perspective_zo`/`matrix_perspective_zo`.
- Functions `pmatrix_perspective_fov`/`matrix_perspective_fov` based on the old `pmatrix_perspective_fov_zo`/`matrix_perspective_fov_zo`.

### Removed

- Functions `pmatrix_ortho_zo`/`matrix_ortho_zo`.
- Functions `pmatrix_ortho_no`/`matrix_ortho_no`.
- Old functions `pmatrix_ortho`/`matrix_ortho`.
- Functions `pmatrix_perspective_zo`/`matrix_perspective_zo`.
- Functions `pmatrix_perspective_no`/`matrix_perspective_no`.
- Functions `pmatrix_perspective_fov_zo`/`matrix_perspective_fov_zo`.
- Functions `pmatrix_perspective_fov_no`/`matrix_perspective_fov_no`.

## 0.1.0 - 2017-11-11

### Added

- This CHANGELOG file.
