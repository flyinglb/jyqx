//
// cangjingge.c ѩɽ�ؾ���
// by secret

inherit ROOM;

string* books = ({
        "/clone/book/mizong_book",
        "/clone/book/skin",
	"/clone/book/book-bamboo",
        "/clone/book/book-silk",
	"/clone/book/book-stone",
	"/clone/book/book-iron",
	"/clone/book/hammer_book1",
	"/clone/book/hammer_book2",
});
void create()
{
        set("short", "ѩɽ�ؾ���");
	set("long", @LONG
������ѩɽ�µĲؾ��ң���ǽ��һ����ܣ������˸�
��ȭ�ס��鼮������ǵ����������Ħ�Ƿ���ķ𾭺ʹ�
������ȡ������ѧ�伮��
LONG );
	set("exits", ([
                "southeast" : __DIR__"dating",
	]));

	set("objects", ([
		books[random(sizeof(books))] : 1,
		books[random(sizeof(books))] : 1,
		books[random(sizeof(books))] : 1,
                CLASS_D("xueshan")+"/daerba" : 1,
	]));
//        set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
