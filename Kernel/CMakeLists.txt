if (ENABLE_EXTRA_KERNEL_DEBUG_SYMBOLS)
    add_compile_options(-Og)
    add_compile_options(-ggdb3)
else()
    add_compile_options(-Os)
endif()

if ("${SERENITY_ARCH}" STREQUAL "i686")
    set(KERNEL_ARCH i386)
elseif("${SERENITY_ARCH}" STREQUAL "x86_64")
    set(KERNEL_ARCH x86_64)
endif()

set(KERNEL_HEAP_SOURCES
    Heap/SlabAllocator.cpp
    Heap/kmalloc.cpp
)

set(KERNEL_SOURCES
    ACPI/DynamicParser.cpp
    ACPI/Initialize.cpp
    ACPI/MultiProcessorParser.cpp
    ACPI/Parser.cpp
    AddressSanitizer.cpp
    Arch/PC/BIOS.cpp
    Arch/x86/SmapDisabler.h
    Bus/PCI/Access.cpp
    Bus/PCI/Device.cpp
    Bus/PCI/DeviceController.cpp
    Bus/PCI/IOAccess.cpp
    Bus/PCI/MMIOAccess.cpp
    Bus/PCI/Initializer.cpp
    Bus/PCI/WindowedMMIOAccess.cpp
    Bus/USB/SysFSUSB.cpp
    Bus/USB/UHCI/UHCIController.cpp
    Bus/USB/UHCI/UHCIRootHub.cpp
    Bus/USB/USBController.cpp
    Bus/USB/USBDevice.cpp
    Bus/USB/USBHub.cpp
    Bus/USB/USBManagement.cpp
    Bus/USB/USBPipe.cpp
    Bus/USB/USBTransfer.cpp
    Bus/VirtIO/VirtIO.cpp
    Bus/VirtIO/VirtIOConsole.cpp
    Bus/VirtIO/VirtIOConsolePort.cpp
    Bus/VirtIO/VirtIOQueue.cpp
    Bus/VirtIO/VirtIORNG.cpp
    CMOS.cpp
    CommandLine.cpp
    ConsoleDevice.cpp
    CoreDump.cpp
    Devices/AsyncDeviceRequest.cpp
    Devices/BlockDevice.cpp
    Devices/CharacterDevice.cpp
    Devices/Device.cpp
    Devices/FullDevice.cpp
    Devices/KCOVDevice.cpp
    Devices/KCOVInstance.cpp
    Devices/MemoryDevice.cpp
    Devices/NullDevice.cpp
    Devices/PCISerialDevice.cpp
    Devices/PCSpeaker.cpp
    Devices/RandomDevice.cpp
    Devices/SB16.cpp
    Devices/SerialDevice.cpp
    Devices/VMWareBackdoor.cpp
    Devices/ZeroDevice.cpp
    Devices/HID/I8042Controller.cpp
    Devices/HID/HIDManagement.cpp
    Devices/HID/KeyboardDevice.cpp
    Devices/HID/MouseDevice.cpp
    Devices/HID/PS2KeyboardDevice.cpp
    Devices/HID/PS2MouseDevice.cpp
    Devices/HID/VMWareMouseDevice.cpp
    GlobalProcessExposed.cpp
    Graphics/Bochs/GraphicsAdapter.cpp
    Graphics/Console/GenericFramebufferConsole.cpp
    Graphics/Console/ContiguousFramebufferConsole.cpp
    Graphics/Console/TextModeConsole.cpp
    Graphics/Console/VGAConsole.cpp
    Graphics/FramebufferDevice.cpp
    Graphics/GraphicsManagement.cpp
    Graphics/Intel/NativeGraphicsAdapter.cpp
    Graphics/VirtIOGPU/FrameBufferDevice.cpp
    Graphics/VirtIOGPU/Console.cpp
    Graphics/VirtIOGPU/GPU.cpp
    Graphics/VirtIOGPU/GraphicsAdapter.cpp
    Graphics/VGACompatibleAdapter.cpp
    SanCov.cpp
    Storage/Partition/DiskPartition.cpp
    Storage/Partition/DiskPartitionMetadata.cpp
    Storage/Partition/EBRPartitionTable.cpp
    Storage/Partition/GUIDPartitionTable.cpp
    Storage/Partition/MBRPartitionTable.cpp
    Storage/Partition/PartitionTable.cpp
    Storage/StorageDevice.cpp
    Storage/AHCIController.cpp
    Storage/AHCIPort.cpp
    Storage/AHCIPortHandler.cpp
    Storage/SATADiskDevice.cpp
    Storage/BMIDEChannel.cpp
    Storage/IDEController.cpp
    Storage/IDEChannel.cpp
    Storage/PATADiskDevice.cpp
    Storage/RamdiskController.cpp
    Storage/RamdiskDevice.cpp
    Storage/StorageManagement.cpp
    DoubleBuffer.cpp
    FileSystem/AnonymousFile.cpp
    FileSystem/BlockBasedFileSystem.cpp
    FileSystem/Custody.cpp
    FileSystem/DevFS.cpp
    FileSystem/DevPtsFS.cpp
    FileSystem/Ext2FileSystem.cpp
    FileSystem/FIFO.cpp
    FileSystem/File.cpp
    FileSystem/FileBackedFileSystem.cpp
    FileSystem/FileDescription.cpp
    FileSystem/FileSystem.cpp
    FileSystem/Inode.cpp
    FileSystem/InodeFile.cpp
    FileSystem/InodeWatcher.cpp
    FileSystem/ISO9660FileSystem.cpp
    FileSystem/Mount.cpp
    FileSystem/Plan9FileSystem.cpp
    FileSystem/ProcFS.cpp
    FileSystem/SysFS.cpp
    FileSystem/SysFSComponent.cpp
    FileSystem/TmpFS.cpp
    FileSystem/VirtualFileSystem.cpp
    FutexQueue.cpp
    Interrupts/APIC.cpp
    Interrupts/GenericInterruptHandler.cpp
    Interrupts/IOAPIC.cpp
    Interrupts/IRQHandler.cpp
    Interrupts/InterruptManagement.cpp
    Interrupts/PIC.cpp
    Interrupts/SharedIRQHandler.cpp
    Interrupts/SpuriousInterruptHandler.cpp
    Interrupts/UnhandledInterruptHandler.cpp
    KBufferBuilder.cpp
    KLexicalPath.cpp
    KString.cpp
    KSyms.cpp
    Memory/AddressSpace.cpp
    Memory/AnonymousVMObject.cpp
    Memory/InodeVMObject.cpp
    Memory/MemoryManager.cpp
    Memory/PageDirectory.cpp
    Memory/PhysicalPage.cpp
    Memory/PhysicalRegion.cpp
    Memory/PhysicalZone.cpp
    Memory/PrivateInodeVMObject.cpp
    Memory/ProcessPagingScope.cpp
    Memory/Region.cpp
    Memory/RingBuffer.cpp
    Memory/ScatterGatherList.cpp
    Memory/SharedInodeVMObject.cpp
    Memory/VMObject.cpp
    Memory/VirtualRange.cpp
    Memory/VirtualRangeAllocator.cpp
    MiniStdLib.cpp
    Locking/Mutex.cpp
    Net/E1000ENetworkAdapter.cpp
    Net/E1000NetworkAdapter.cpp
    Net/IPv4Socket.cpp
    Net/LocalSocket.cpp
    Net/LoopbackAdapter.cpp
    Net/NE2000NetworkAdapter.cpp
    Net/NetworkAdapter.cpp
    Net/NetworkTask.cpp
    Net/NetworkingManagement.cpp
    Net/RTL8139NetworkAdapter.cpp
    Net/RTL8168NetworkAdapter.cpp
    Net/Routing.cpp
    Net/Socket.cpp
    Net/TCPSocket.cpp
    Net/UDPSocket.cpp
    Panic.cpp
    PerformanceEventBuffer.cpp
    Process.cpp
    ProcessExposed.cpp
    ProcessSpecificExposed.cpp
    ProcessGroup.cpp
    ProcessProcFSTraits.cpp
    RTC.cpp
    Random.cpp
    Scheduler.cpp
    StdLib.cpp
    Syscall.cpp
    Syscalls/anon_create.cpp
    Syscalls/access.cpp
    Syscalls/alarm.cpp
    Syscalls/beep.cpp
    Syscalls/chdir.cpp
    Syscalls/chmod.cpp
    Syscalls/chown.cpp
    Syscalls/clock.cpp
    Syscalls/debug.cpp
    Syscalls/disown.cpp
    Syscalls/dup2.cpp
    Syscalls/emuctl.cpp
    Syscalls/execve.cpp
    Syscalls/exit.cpp
    Syscalls/fcntl.cpp
    Syscalls/fork.cpp
    Syscalls/ftruncate.cpp
    Syscalls/futex.cpp
    Syscalls/get_dir_entries.cpp
    Syscalls/get_stack_bounds.cpp
    Syscalls/getrandom.cpp
    Syscalls/getuid.cpp
    Syscalls/hostname.cpp
    Syscalls/ioctl.cpp
    Syscalls/keymap.cpp
    Syscalls/kill.cpp
    Syscalls/link.cpp
    Syscalls/lseek.cpp
    Syscalls/mkdir.cpp
    Syscalls/mknod.cpp
    Syscalls/mmap.cpp
    Syscalls/module.cpp
    Syscalls/mount.cpp
    Syscalls/open.cpp
    Syscalls/perf_event.cpp
    Syscalls/pipe.cpp
    Syscalls/pledge.cpp
    Syscalls/prctl.cpp
    Syscalls/process.cpp
    Syscalls/profiling.cpp
    Syscalls/ptrace.cpp
    Syscalls/purge.cpp
    Syscalls/read.cpp
    Syscalls/readlink.cpp
    Syscalls/realpath.cpp
    Syscalls/rename.cpp
    Syscalls/rmdir.cpp
    Syscalls/sched.cpp
    Syscalls/select.cpp
    Syscalls/sendfd.cpp
    Syscalls/setpgid.cpp
    Syscalls/setuid.cpp
    Syscalls/shutdown.cpp
    Syscalls/sigaction.cpp
    Syscalls/socket.cpp
    Syscalls/stat.cpp
    Syscalls/statvfs.cpp
    Syscalls/sync.cpp
    Syscalls/sysconf.cpp
    Syscalls/thread.cpp
    Syscalls/times.cpp
    Syscalls/ttyname.cpp
    Syscalls/umask.cpp
    Syscalls/uname.cpp
    Syscalls/unlink.cpp
    Syscalls/unveil.cpp
    Syscalls/utime.cpp
    Syscalls/waitid.cpp
    Syscalls/inode_watcher.cpp
    Syscalls/write.cpp
    TTY/ConsoleManagement.cpp
    TTY/MasterPTY.cpp
    TTY/PTYMultiplexer.cpp
    TTY/SlavePTY.cpp
    TTY/TTY.cpp
    TTY/VirtualConsole.cpp
    Tasks/FinalizerTask.cpp
    Tasks/SyncTask.cpp
    Thread.cpp
    ThreadBlockers.cpp
    ThreadTracer.cpp
    Time/APICTimer.cpp
    Time/HPET.cpp
    Time/HPETComparator.cpp
    Time/PIT.cpp
    Time/RTC.cpp
    Time/TimeManagement.cpp
    TimerQueue.cpp
    UBSanitizer.cpp
    UserOrKernelBuffer.cpp
    WaitQueue.cpp
    WorkQueue.cpp
    init.cpp
    kprintf.cpp
)

set(KERNEL_SOURCES
    ${KERNEL_SOURCES}
    ${CMAKE_CURRENT_SOURCE_DIR}/Arch/x86/${KERNEL_ARCH}/ASM_wrapper.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Arch/x86/${KERNEL_ARCH}/Boot/ap_setup.S
    ${CMAKE_CURRENT_SOURCE_DIR}/Arch/x86/${KERNEL_ARCH}/InterruptEntry.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Arch/x86/${KERNEL_ARCH}/Processor.cpp
)

set(KERNEL_SOURCES
    ${KERNEL_SOURCES}
    ${CMAKE_CURRENT_SOURCE_DIR}/Arch/x86/common/ASM_wrapper.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Arch/x86/common/CPU.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Arch/x86/common/Interrupts.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Arch/x86/common/Processor.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Arch/x86/common/ProcessorInfo.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Arch/x86/common/SafeMem.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Arch/x86/common/TrapFrame.cpp
)

set(AK_SOURCES
    ../AK/FlyString.cpp
    ../AK/GenericLexer.cpp
    ../AK/Hex.cpp
    ../AK/String.cpp
    ../AK/StringBuilder.cpp
    ../AK/StringImpl.cpp
    ../AK/StringUtils.cpp
    ../AK/StringView.cpp
    ../AK/Time.cpp
    ../AK/Format.cpp
    ../AK/UUID.cpp
    ../AK/Utf8View.cpp
    ../AK/Utf16View.cpp
)

set(ELF_SOURCES
    ../Userland/Libraries/LibELF/Image.cpp
    ../Userland/Libraries/LibELF/Validation.cpp
)

generate_state_machine(../Userland/Libraries/LibVT/StateMachine.txt ../Userland/Libraries/LibVT/EscapeSequenceStateMachine.h)

set(VT_SOURCES
    ../Userland/Libraries/LibVT/Terminal.cpp
    ../Userland/Libraries/LibVT/Line.cpp
    ../Userland/Libraries/LibVT/EscapeSequenceParser.cpp
)

set(KEYBOARD_SOURCES
    ../Userland/Libraries/LibKeyboard/CharacterMap.cpp
)

set(CRYPTO_SOURCES
    ../Userland/Libraries/LibCrypto/Cipher/AES.cpp
    ../Userland/Libraries/LibCrypto/Hash/SHA2.cpp
)

set(SOURCES
    ${KERNEL_SOURCES}
    ${AK_SOURCES}
    ${ELF_SOURCES}
    ${VT_SOURCES}
    ${KEYBOARD_SOURCES}
    ${CRYPTO_SOURCES}
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-unknown-warning-option -Wvla -Wnull-dereference")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-rtti -ffreestanding -fbuiltin")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mno-80387 -mno-mmx -mno-sse -mno-sse2")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-asynchronous-unwind-tables")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fstack-protector-strong")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-exceptions")
# FIXME: remove -nodefaultlibs after the next toolchain update
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -nodefaultlibs -nostdlib")

if (USE_CLANG_TOOLCHAIN)
    add_compile_options(-Waddress-of-packed-member)
endif()

# Apply any flags that are only available on >= GCC 11.1
if (NOT USE_CLANG_TOOLCHAIN AND CMAKE_COMPILER_IS_GNUCXX AND CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL 11.1)
    # Zero any registers used within a function on return (to reduce data lifetime and ROP gadgets).
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fzero-call-used-regs=used-gpr")
endif()

if (NOT USE_CLANG_TOOLCHAIN)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -nostdinc -nostdinc++")
endif()

macro (set_new_alignment alignment)
    if (USE_CLANG_TOOLCHAIN)
        add_compile_options(-faligned-allocation)
        add_compile_options(-fnew-alignment=${alignment})
    else()
        add_compile_options(-faligned-new=${alignment})
    endif()
endmacro()

if ("${SERENITY_ARCH}" STREQUAL "x86_64")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mcmodel=large -mno-red-zone")
    set_new_alignment(8)
else()
    set_new_alignment(4)
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-pie")

# Kernel Coverage (KCOV) is an API to collect and expose program counters of
# kernel code that has been run to user space. It's rather slow and likely not
# secure to run in production builds. Useful for coverage guided fuzzing.
if (ENABLE_KERNEL_COVERAGE_COLLECTION)
    add_definitions(-DENABLE_KERNEL_COVERAGE_COLLECTION)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize-coverage=trace-pc")
    set(KCOV_EXCLUDED_SOURCES
        # Make sure we don't instrument any code called from __sanitizer_cov_trace_pc
        # otherwise we'll end up with recursive calls to that function.
        ../AK/Format.cpp
        ../AK/StringBuilder.cpp
        ../Kernel/Arch/x86/${KERNEL_ARCH}/Processor.cpp
        ../Kernel/Devices/KCOVDevice.cpp
        ../Kernel/Devices/KCOVInstance.cpp
        ../Kernel/FileSystem/File.cpp
        ../Kernel/FileSystem/FileDescription.cpp
        ../Kernel/Heap/SlabAllocator.cpp
        ../Kernel/init.cpp
        ../Kernel/SanCov.cpp
        # GCC assumes that the caller saves registers for functions according
        # to the System V ABI and happily inserts coverage calls into the
        # function prologue for all functions. This assumption is not true for
        # interrupt handlers because their calling convention is not compatible
        # with the System V ABI.
        ../Kernel/Arch/x86/common/Interrupts.cpp
        ../Kernel/Syscall.cpp
    )
    set_source_files_properties(${KCOV_EXCLUDED_SOURCES} PROPERTIES COMPILE_FLAGS "-fno-sanitize-coverage=trace-pc")
endif()

# Kernel Undefined Behavior Sanitizer (KUBSAN)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=undefined")

# Kernel Address Sanitize (KASAN) implementation is still a work in progress, this option
# is not currently meant to be used, besides when developing Kernel ASAN support.
#
if (ENABLE_KERNEL_ADDRESS_SANITIZER)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=kernel-address")
endif()

add_compile_definitions(KERNEL)

# HACK: This is a workaround for CLion to grok the kernel sources.
#       It's needed because CLion doesn't understand the way we switch compilers mid-build.
add_compile_definitions(__serenity__)

add_link_options(LINKER:-z,notext)

if (USE_CLANG_TOOLCHAIN)
    add_link_options(LINKER:--build-id=none)
endif()

add_library(kernel_heap STATIC ${KERNEL_HEAP_SOURCES})

if (${CMAKE_HOST_SYSTEM_NAME} MATCHES SerenityOS)
    include_directories(/usr/local/include/c++/${GCC_VERSION}/)
elseif (USE_CLANG_TOOLCHAIN)
    include_directories("${TOOLCHAIN_ROOT}/include/c++/v1")
else()
    if (NOT EXISTS ${TOOLCHAIN_ROOT}/${SERENITY_ARCH}-pc-serenity/include/c++/${GCC_VERSION}/)
        message(FATAL_ERROR "Toolchain version ${GCC_VERSION} (${SERENITY_ARCH}) appears to be missing! Please run: Meta/serenity.sh rebuild-toolchain ${SERENITY_ARCH}")
    endif()
    include_directories(${TOOLCHAIN_ROOT}/${SERENITY_ARCH}-pc-serenity/include/c++/${GCC_VERSION}/)
    include_directories(${TOOLCHAIN_ROOT}/${SERENITY_ARCH}-pc-serenity/include/c++/${GCC_VERSION}/${SERENITY_ARCH}-pc-serenity/)
endif()

if (NOT USE_CLANG_TOOLCHAIN)
    link_directories(${TOOLCHAIN_ROOT}/${SERENITY_ARCH}-pc-serenity/lib)
    link_directories(${TOOLCHAIN_ROOT}/lib/gcc/${SERENITY_ARCH}-pc-serenity/${GCC_VERSION}/)
endif()

add_executable(Kernel ${SOURCES})
add_dependencies(Kernel generate_EscapeSequenceStateMachine.h)

add_custom_command(
    OUTPUT linker.ld
    COMMAND "${CMAKE_CXX_COMPILER}" -E -P -x c -I${CMAKE_CURRENT_SOURCE_DIR}/.. "${CMAKE_CURRENT_SOURCE_DIR}/linker.ld" -o "${CMAKE_CURRENT_BINARY_DIR}/linker.ld"
    MAIN_DEPENDENCY "${CMAKE_CURRENT_SOURCE_DIR}/linker.ld"
    COMMENT "Preprocessing linker.ld"
    VERBATIM
)

add_custom_target(generate_kernel_linker_script DEPENDS linker.ld)

target_link_options(Kernel PRIVATE LINKER:-T ${CMAKE_CURRENT_BINARY_DIR}/linker.ld -nostdlib)
set_target_properties(Kernel PROPERTIES LINK_DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/linker.ld")

if (ENABLE_KERNEL_LTO)
    include(CheckIPOSupported)
    check_ipo_supported()
    set_property(TARGET Kernel PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)
endif()

if (USE_CLANG_TOOLCHAIN)
    target_link_libraries(Kernel kernel_heap clang_rt.builtins-${SERENITY_CLANG_ARCH})
else()
    target_link_libraries(Kernel kernel_heap gcc)
endif()

add_dependencies(Kernel kernel_heap)

add_custom_command(
    TARGET Kernel POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E env CXXFILT=${CMAKE_CXXFILT} sh ${CMAKE_CURRENT_SOURCE_DIR}/mkmap.sh
    COMMAND ${CMAKE_COMMAND} -E env OBJCOPY=${CMAKE_OBJCOPY} sh ${CMAKE_CURRENT_SOURCE_DIR}/embedmap.sh
    COMMAND ${CMAKE_OBJCOPY} --only-keep-debug Kernel Kernel.debug
    COMMAND ${CMAKE_OBJCOPY} --strip-debug Kernel
    COMMAND ${CMAKE_OBJCOPY} --add-gnu-debuglink=Kernel.debug Kernel
    BYPRODUCTS ${CMAKE_CURRENT_BINARY_DIR}/kernel.map
)

install(FILES "${CMAKE_CURRENT_BINARY_DIR}/Kernel" DESTINATION boot)
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/Kernel.debug" DESTINATION boot)
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/kernel.map" DESTINATION res)

serenity_install_headers(Kernel)
serenity_install_sources(Kernel)

add_subdirectory(Prekernel)
add_subdirectory(Modules)
