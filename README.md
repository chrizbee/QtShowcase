## Basic Overview
**QtShowcase** is a *Qt5-Application* that is based on the [QtWidget Gallery](https://doc.qt.io/qt-5/gallery.html).
The app should showcase [QtStyler](https://github.com/chrizbee/QtStyler).

## Getting Started

Get started by by building it with `qmake` and `make` (for *Windows*, *Linux* and *Mac*).

### Prerequisites

To build this application, you will need Qt5. If you are going to build on Windows, you need to make sure, that your `PATH` variable contains paths to *Qt* and *MinGW* / *MSVC* toolsets (*bin* folder).

### Building

Clone the GitHub repository
```bash
git clone https://github.com/chrizbee/QtShowcase
cd QtShowcase
```

Build it using `qmake` and `make`
```bash
qmake
make [release | debug]
```

Run the application
```bash
cd build
./QtShowcase
```

## Deployment

- **Linux** - [linuxdeployqt](https://github.com/probonopd/linuxdeployqt)
- **Windows** - [windeployqt](https://doc.qt.io/qt-5/windows-deployment.html)

## Built With

* [Qt5](https://www.qt.io/) - The UI framework used

## Versioning

We use [SemVer](http://semver.org/) for versioning. The current version is stored in [QtShowcase.pro](QtShowcase.pro) (`VERSION`).

## Authors

- [chrizbee](https://github.com/chrizbee)

See also the list of [contributors](https://github.com/chrizbee/QtShowcase/contributors) who participated in this project.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments & Sources

- Icons by [Icons8](https://icons8.com/)
