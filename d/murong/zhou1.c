// /u/beyond/mr/zhou1.c
// this is made by beyond
// update 1997.6.20
inherit ROOM;
void create()
{
	set("short", "С��");
	set("long", @LONG
һҶС�ۣ����Ҳ�������ߡ��˸��ˡ�һ����ʮ������������ֳֳ���
�ݣ����ڴ�β�����س��Ŵ���
LONG
	);
        set("no_fight",1);

	setup();
}
void run(object ob)
{
       	if (environment(ob) == this_object())
       	ob->move(__DIR__"zhou2", 1);
	write("\nС��ʻ��һƬһ���޼ʵĺɻ�����һ����ȥ, ������Ҷ, ��Ҷ, «έ, ����,\n"
"����һģһ��, ��֮��Ҷ, ��Ҷ��ˮ��Ư��, ��ʱһ�����, �㼴�仯�ٶˣ�\n"
"����˿̼ǵ��������, ��ʱ������ȫȻ��ͬ��С���ںɻ����л������У�\n"
"ת��һ�Ŵ���, ԶԶ����ˮ��С�ӵ�һ�����ܡ���ֻ�����ͷ���ӹ���\n\n");
}

void init()
{
       object ob = this_player();

    call_out("run", 10, ob);
}

