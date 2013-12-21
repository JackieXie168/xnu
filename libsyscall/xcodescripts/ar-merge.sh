set -e

# This line makes it so that the files are broken on newlines, not spaces.
IFS='
'

for AR_FILE in `cat "${INPUT_FILE_PATH}"`; do
    FIXED_AR_FILE=`eval echo $AR_FILE`
    
    for LINE in `ar t $FIXED_AR_FILE`; do
        # Ignore the symbol index automatically inserted by libtool
        [[ "$LINE" == "__.SYMDEF SORTED" ]] && continue
        
        ar x "${FIXED_AR_FILE}" "${DERIVED_FILE_DIR}/${LINE}"
        OBJECT_FILES=("${OBJECT_FILES[@]}" "${DERIVED_FILE_DIR}/${LINE}")
    done
done

cc -nostdlib -r -o "${DERIVED_FILE_DIR}/${INPUT_FILE_BASE}.o" "${OBJECT_FILES[@]}"
# rm "${OBJECT_FILES[@]}"
