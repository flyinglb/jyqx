// sexliterate.c ����ѧ����

string look_shelf();

#define STORY_TOC   "/doc/story/toc"
#define STORY_DIR "/doc/story/"
inherit ROOM;

void create()
{
	set("short", "����ѧͼ���");
	set("long", @LONG
����һ�伫Ϊ���ε�ͼ���ղ��ҡ�������� read ���Ķ�һЩ��� (shelf)
�ϵĻ�ɫС˵��
LONG );
        set("item_desc", ([
                "shelf" : (: look_shelf :),
        ]));
	set("exits", ([
		"south" : __DIR__"lichunyuan",
	]));
	set("no_clean_up", 0);
	setup();
//	replace_program(ROOM);
}

void init()
{
	add_action("do_read", "read");
}

string look_shelf()
{
        this_player()->start_more(read_file(STORY_TOC));
        return "\n";
}

int do_read(string arg)
{
        if (arg == "" || file_size(STORY_DIR + arg) <= 0)
                return notify_fail("����û���Ȿ�顣\n");

	switch (MONEY_D->player_pay(this_player(), 20000)) {
	        case 0:
                return notify_fail("��⵰��һ�ߴ���ȥ��\n");
	        case 2:
                return notify_fail("������Ǯ�����ˣ���Ʊ��û���ҵÿ���\n");
	}
	log_file("LIBRARY", sprintf("%s read %s.\n", this_player()->query("name"), arg));
	this_player()->start_more(read_file(STORY_DIR + arg));
	return 1;
}
