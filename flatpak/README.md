Build
```sh
flatpak-builder --force-clean --user --install-deps-from=flathub --repo=repo --install builddir io.github.mk64recomp.mk64recomp.json
```

Bundle
```sh
flatpak build-bundle repo io.github.mk64recomp.mk64recomp.flatpak io.github.mk64recomp.mk64recomp --runtime-repo=https://flathub.org/repo/flathub.flatpakrepo
```

