#include "Archive.h"
#include "File.h"
#include "Constants.h"
#include "Stat.h"

#include <nan.h>
#include <zip.h>

NAN_MODULE_INIT(Init) {
    SetNativeConstants(target);
    SetZipConstants(target);
    SetZipStatFlags(target);
    bindings::libzip::Stat::Init(target);
    File::Init(target);
    Archive::Init(target);
}

NODE_MODULE(libzip, Init)
