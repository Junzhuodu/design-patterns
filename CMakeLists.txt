cmake_minimum_required(VERSION 3.5)

project(CppDesignPatterns)

set (CMAKE_CXX_STANDARD 11)

set(PATTERNS
        CreationalPatterns/abstract-factory
        CreationalPatterns/builder
        CreationalPatterns/factory-method
        CreationalPatterns/prototype
        CreationalPatterns/singleton

        StructuralPatterns/adapter
        StructuralPatterns/bridge
        StructuralPatterns/proxy
        StructuralPatterns/composite
        StructuralPatterns/decorator
        StructuralPatterns/facade
        StructuralPatterns/flyweight

        BehaviroalPatterns/chain-of-responsibility
        BehaviroalPatterns/command
        BehaviroalPatterns/interpreter
        BehaviroalPatterns/iterator
        BehaviroalPatterns/mediator
        BehaviroalPatterns/memento
        BehaviroalPatterns/observer
        BehaviroalPatterns/state
        BehaviroalPatterns/strategy
        BehaviroalPatterns/template-method
        BehaviroalPatterns/visitor
        )

foreach(_dir IN ITEMS ${PATTERNS})
    file(GLOB _files "${_dir}/*.cxx")
    message(STATUS "Pattern `${_dir}':")

    foreach(_file IN ITEMS ${_files})

        get_filename_component(_file_name
                ${_file} NAME
                )

        set(_project_name "${_file_name}")
        message(STATUS "  ${_dir}/${_file_name} is going to be built")

        add_executable(${_project_name} "${_dir}/${_file_name}")
    endforeach()

endforeach()
