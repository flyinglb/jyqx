// /u/beyond/mr/xiaozhou1.c
// this is made by beyond
// update 1997.6.20
inherit ROOM;
void create()
{
	set("short", "�ɴ�");
	set("long", @LONG
һҶС�ۣ����Ҳ�������ߡ��˸��ˡ�һ���ϴ����ֳֳ���ݣ����ڴ�
β�����س��Ŵ����������ȥ�������ϵ�������ɫʹ�㸡����ƪ��
LONG
	);
        set("no_fight",1);
	setup();
}
void run(object ob)
{
       	if (environment(ob) == this_object())
       	ob->move(__DIR__"xiaozhou2");
	write("\nС��ʻ��һƬһ���޼ʵĺɻ�����һ����ȥ, ������Ҷ, ��Ҷ, «έ, ����,\n"
"����һģһ��, ��֮��Ҷ, ��Ҷ��ˮ��Ư��, ��ʱһ�����, �㼴�仯�ٶˣ�\n"
"����˿̼ǵ��������, ��ʱ������ȫȻ��ͬ��\n\n");
}

void init()
{
       object ob = this_player();

    call_out("run", 10, ob);
}




