// roomd.c
// Written by Doing Lu 1998/11/14

// ��������SECURITD�Ĳ�ѯ������һ��object���̵��ĵ�����SECURITYD�Ƚ����
// �ĵ���������object������д����ĵ��������һ�£�����д�롣

void create()
{
	seteuid(getuid());
}

string get_file_name(object ob)
{
	string file;
	if (objectp(ob))
	{		
		file = base_name(ob) + ".sav"; 
		// �������һ����ͨ�Ŀɼ�¼�ķ��ݣ������ļ�Ҫ�����/data/room��
		// ������Ǽ�¼�ķ��ݣ��ֲ���˽�з��ݣ����ܼ�¼��
		if (ob->query("recordable_room")) file = "/data/room" + file; else
		if (! ob->query("private_room")) file = "";
	} else
		file = "";

	return file;
}
