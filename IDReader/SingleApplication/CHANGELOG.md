Changelog
=========

__v3.0a__
--------

*   Depricated meximum secondary instances count setting.
*   Added a sendMessage() method to send a message to the primary instance.
*   Added a receivedMessage() signal, emmited when a message is received from a
    secondary instance.
*   The SingleApplication constructor's third parameter is now a bool
    specifying if the current instance should be allowed to run as a secondary
    instance of there is already a primary instance.
*   The SingleApplication constructor accept a fourth parameter specifying if
    the SingleApplication block should be User-wide or System-wide.
*   SingleApplication no longer relies on `applicationName` and
    `organizationName` to be set. It instead concatenates all of the following
    data and computes a `SHA256` hash which is uses as the key for the
    `QSharedMemory` block and the `QLocalServer`. Since at least
    `applicationFilePath` is always present there is no need to explicitly set
    any of these prior to initialising `SingleApplication`.
        * QCoreApplication::applicationName
        * QCoreApplication::applicationVersion
        * QCoreApplication::applicationFilePath
        * QCoreApplication::organizationName
        * QCoreApplication::organizationDomain
        * User name or home directory path if in User mode
*   The primary instance is no longer notified when a secondary instance had
    been started by default. An setting for this feature exists.
*   Added instanceNumber() which represents a unique identifier for each
    secondary instance started. When called from the primary instance will
    return `0`.

__v2.4__
--------

*   Stability improvements
*   Support for secondary instances.
*   The library now recovers safely after the primary process has crashed
and the shared memory had not been deleted.

__v2.3__
--------

*   Improved pimpl design and inheritance safety.

    _Vladislav Pyatnichenko_

__v2.2__
--------

*   The `QAPPLICATION_CLASS` macro can now be defined in the file including the
Single Application header or with a `DEFINES+=` statement in the project file.

__v2.1__
--------

*   A race condition can no longer occur when starting two processes nearly
    simultaneously.

    Fix issue [#3](https://github.com/itay-grudev/SingleApplication/issues/3)

__v2.0__
--------

*   SingleApplication is now being passed a reference to `argc` instead of a
    copy.

    Fix issue [#1](https://github.com/itay-grudev/SingleApplication/issues/1)

*   Improved documentation.
