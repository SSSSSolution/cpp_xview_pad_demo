#!/bin/bash

set -e

function usage()
{
    echo "$0 -r <repo_addr> -b <branch> [-c <commit>] -d <proto_root_dir> -t <target> -o <output_dir>"
}

POSITIONAL_ARGS=()

TARGETS=()

function check_param()
{
    if [[ -z "$1" ]] || [[ "$1" =~ "^-.*" ]]; then
       usage
       exit 1
    fi
}

while [[ $# -gt 0 ]]; do
    case $1 in
        -r)
            check_param $2
            REPO_ADDR=$2
            shift
            shift
            ;;
        -b)
            check_param $2
            BRANCH=$2
            shift
            shift
            ;;
        -c)
            check_param $2
            COMMIT=$2
            shift
            shift
            ;;
        -d)
            check_param $2
            PROTO_ROOT_DIR=$2
            shift
            shift
            ;;
        -t)
            check_param $2
            TARGETS+=("$2")
            shift
            shift
            ;;
        -o)
            check_param $2
            OUTPUT_DIR=$2
            shift
            shift
            ;;
        *)
            check_param $2
            POSITION_ARGS+=("$1")
            shift
            ;;
    esac
done

set -- "${POSITIONAL_ARGS[@]}"


# check input
if [ -z "${REPO_ADDR}" ] || [ -z "${BRANCH}" ] ||
   [ -z "${PROTO_ROOT_DIR}" ] || [ -z "${TARGETS}" ] ||
   [ -z "${OUTPUT_DIR}" ]; then
    usage
    exit 1
fi


# print params
echo "REPO_ADDR         = ${REPO_ADDR}"
echo "BRANCH            = ${BRANCH}"
echo "COMMIT            = ${COMMIT}"
echo "PROTO_ROOT_DIR    = ${PROTO_ROOT_DIR}"
echo "OUTPUT_DIR        = ${OUTPUT_DIR}"
echo "TARGETS:"

for target in ${TARGETS[@]}; do
    echo "                    ${target}"
done

















