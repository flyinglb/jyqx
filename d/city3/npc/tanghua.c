// tanghua.c

inherit NPC;

void create()
{
        set_name("���ƹ�", ({ "tang", "boss" }) );
        set("long",
                "���ƹ�����Ҵ��¥�����ˣ�����ֻ��һ��СС�ľ�¥�ϰ壬�ڳ�\n"
                "�������ᶽ��ү���⣬���¾�������ƴ��ƴ�\n" );
        set("age", 46);
        set("attitude", "peaceful");
	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_temp("apply/attack", 30);
	set_temp("apply/attack", 30);
	set_temp("apply/damage", 15);

	set("combat_exp", 50000);
	set("attitude", "friendly");
	
        set("inquiry", ([
                "name": "�������Ƶ���һ�����֡�\n",
                "here": "�˴������سǾ�¥��������Ҫ��ˣ��Ը������С��һ����ɡ�\n",
                "����": "���ң����±������룬��֪�����кηԸ���\n",
                "�سǾ�¥": "������ǣ������ǵ�һ������\n"
        ]) );
        setup();
        add_money("silver", 15);
        carry_object("/clone/misc/cloth")->wear();
}

