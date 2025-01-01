TOPTARGETS := all clean
SUBDIRS := libcpm libutil hello tree

$(TOPTARGETS): $(SUBDIRS)
$(SUBDIRS):
	$(MAKE) -C $@ $(MAKECMDGOALS)

.PHONY: $(TOPTAGETS) $(SUBDIRS)
