// caoyao.c ��ҩ

inherit ITEM;

void create()
{
        set_name("��ҩ", ({ "cao yao",  }));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�ò�֪����ҩ�ݡ�\n");
        set("value", 0);
	}
}

void init()
{
        object who = this_player();
        if(environment() == who) {
        if(who->query_temp("job_xiaoyao") 
        && who->query("family/family_name") == "��ң��")
        set("long","����һ�ò������۵Ĳ�ҩ�������ⶫ�������û�ȥ���\n");
        set("job", 1);//�������
        }
}
