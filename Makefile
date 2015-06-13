exclude_dirs := gtest-1.7.0

dirs := $(shell find . -maxdepth 1 -type d)
dirs := $(basename $(patsubst ./%,%,$(dirs)))
dirs := $(filter-out $(exclude_dirs),$(dirs))

SUBDIRS := $(dirs)
CLEAN_DIRS := $(addprefix _clean_, $(SUBDIRS))

.PHONY: $(SUBDIRS) clean

$(SUBDIRS):
	$(MAKE) -C $@

clean: $(CLEAN_DIRS)

$(CLEAN_DIRS):
	$(MAKE) -C $(patsubst _clean_%, %, $@) clean

