// mei.c
inherit NPC;

void create()
{
        set_name( "÷����" ,({ "mei chaofeng", "mei" }));
        set("nickname", "��ʬ");
        set("gender", "Ů��");
        set("age", 39);
        set("long",
            "÷�����ǻ�ҩʦΨһ��Ů���ӣ��������ܻ�ҩʦ�۰�����ϧ����ʦ�ֳ�����\n"
            "������㺣�����͵�ˡ������澭�¾�˽����\n"
            "����������꣬����������������ϡ����������ķ�ɡ�\n");
        set("attitude", "peaceful");
        set("str", 27);
        set("int", 32);
        set("con", 35);
        set("max_qi",2500);
        set("max_jing",1000);
        set("neili", 2500);
        set("max_neili", 2500);
        set("jiali", 100);
        set("shen",-50000);

        set("combat_exp", 1000000);

        set_skill("unarmed", 80);
        set_skill("force", 80);
        set_skill("parry", 80);
        set_skill("dodge", 40);
        set_skill("sword", 80);
        set_skill("literate", 20);
        set_skill("jiuyin-baiguzhao", 90);
        set_skill("luoying-shenjian",90);
        set_skill("bibo-shengong", 90);
        set_skill("anying-fuxiang", 90);

        map_skill("force", "bibo-shengong");
        map_skill("parry", "luoying-shenjian");
        map_skill("sword", "luoying-shenjian");
        map_skill("dodge", "anying-fuxiang");
        map_skill("unarmed", "jiuyin-baiguzhao");

        create_family("�һ���", 2, "�������");

        set("inquiry", ([
           "�һ���":   "������ǣ��㶼���˻��᲻֪����",
           "��ʬ":     "�����ϵ��˶���ô���ҵģ����²��£�����������",
           "��а":     "������ʦ���Ĵºš�",
           "����":     "�������ʦ�����ĸ���֮һ���Ǹ��϶��ס�ڰ���ɽ��",
           "�ϵ�":     "����ү�ѳ��ҵ�����ȥ�ˣ�������һ�ơ�",
           "��ؤ":     "��ؤͳ����ԭ��ؤ�������Ϊǿ��",
           "���߹�":   "���߹��书��ǿ�����ҽ̻������С������ʮ���ƣ��ɺޣ�",
           "����":     "������ʦ���Ķ�Ů�����ǵ������ԡ�",
           "����":     "�ߣ��������С�Ӱ�������ʦ�磬�Ҿ�����Ź�����",
           "�":     "�������ҵ�ͽ�ܣ��������ô��",
           "÷����":   "��������ô�����ǰ׳հ���",
           "������":   "�����ҵ�ʦ�磬Ҳ���ҵķ������ϧ��������С�������ˡ�",
           "��ҩʦ":   "������ʦ����"]) );
        setup();
      carry_object("/clone/cloth/cloth")->wear();
}

