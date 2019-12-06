// huo.c

inherit NPC;

string ask_for_zigong();
int ask_for_gongzi();

void create()
{
        set_name("������", ({"huo xiansheng", "huo", "xiansheng"}));
        set("long",
"��һ�����ݣ�����ί�����������Ժ�����˯����ģ����������������ʮ�������޿����ޡ�
ԭ�������Ƿ�ţ�ɵĴް�Ȫ��Ϊ�ܳ�������ڴˡ�\n"
        );

        set("gender", "����");
        set("attitude", "heroism");

        set("inquiry",([
                "����"    : (: ask_for_gongzi :),
                "нˮ"    : (: ask_for_gongzi :),
                "salary"  : (: ask_for_gongzi :),
                "payment" : (: ask_for_gongzi :),
                "gongzi"  : (: ask_for_gongzi :),
        ]));

        set("age", 51);
        set("shen_type", 0);
        set("str", 25);
        set("int", 20);
        set("con", 20);
        set("dex", 25);
        set("max_qi", 500);
        set("max_jing", 100);
        set("neili", 500);
        set("max_neili", 500);
        set("jiali", 100);
        set("combat_exp", 100000);
        set("score", 100);
        set("apply/attack",  30);
        set("apply/defense", 30);

        set_skill("force", 50);
        set_skill("unarmed", 50);
        set_skill("sword", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 50);
}

int ask_for_gongzi()
{
        object me,payment;
        int paytimes;
	string oldtitle;

        me = this_player();
	oldtitle = me->query("title");
	if (strsrch(oldtitle, "�������������佫") >= 0) 
	{
	    paytimes = (int)(me->query("mud_age")/7200);
	    if (me->query("dlpaytimes")<paytimes)
	    {
	        payment=new("/clone/money/gold");
	        payment->move(me);
	        me->add("dlpaytimes",1);
	        tell_object(me,"���������������㱾�µķݶ�պðɡ�\n");
	    }
	    else tell_object(me,"�����������۸����Ϻ�Ϳ���㱾�¹����Ѿ���ȡ���ˣ�\n");
	}
	else
	tell_object(me,"�����������۸����Ϻ�Ϳ�����������佫�����칤�ʣ�\n");
        return 1;
}

