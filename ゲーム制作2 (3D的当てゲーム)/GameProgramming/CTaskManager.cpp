#include "CTaskManager.h"

//�^�X�N�}�l�[�W���̊O���ϐ�
//CTaskManager TaskManager;
//�^�X�N�}�l�[�W���̃C���X�^���X
CTaskManager*CTaskManager::mpInstance = 0;

//�C���X�^���X�̎擾
CTaskManager*CTaskManager::Get()
{
	//�C���X�^���X���������
	if (mpInstance == 0)
	{   //�C���X�^���X�𐶐�����
		mpInstance = new CTaskManager();
	}
	return mpInstance;
}

//�f�t�H���g�R���X�g���N�^
CTaskManager::CTaskManager()
{
	mHead.mpNext = &mTail;
	mTail.mpPrev = &mHead;
}
CTaskManager::~CTaskManager(){
}
//���X�g�ɒǉ�
//Add(�^�X�N�̃|�C���^)
void CTaskManager::Add(CTask*addTask)
{
	//mTail�̑O�ɒǉ�
	CTask*task = &mTail;
	//addTask�̎���task
	addTask->mpNext = task;
	//addTask�̑O��task�̑O��
	addTask->mpPrev = task->mpPrev;
	//addTask�̑O�̎���addTask��
	addTask->mpPrev->mpNext = addTask;
	//task�̑O��addTask��
	task->mpPrev = addTask;
}
//�X�V
void CTaskManager::Update(){
	//�擪����Ō�܂ŌJ��Ԃ�
	CTask*task = mHead.mpNext;
	while (task->mpNext){
		//�X�V�������Ă�
		task->Update();
		//����
		task = task->mpNext;
	}
}
//�`��
void CTaskManager::Render(){
	//�擪����Ō�܂ŌJ��Ԃ�
	CTask*task = mHead.mpNext;
	while (task->mpNext){
		//�`�揈�����Ă�
		task->Render();
		//����
		task = task->mpNext;
	}
}

//���X�g����폜
//Remove(�^�X�N�̃|�C���^)
void CTaskManager::Remove(CTask*task){
	//�^�X�N�̑O�̎����A�^�X�N�̎��ɂ���
	task->mpPrev->mpNext = task->mpNext;
	//�^�X�N�̎��̑O���A�^�X�N�̑O�ɂ���
	task->mpNext->mpPrev = task->mpPrev;
}

//�^�X�N�̍폜
void CTaskManager::Delete(){
	//�擪����Ō�܂ŌJ��Ԃ�
	CTask*task = mHead.mpNext;
	while (task->mpNext){
		CTask*del = task;
		//����
		task = task->mpNext;
		//mEnabled��false�Ȃ�폜
		if (del->mEnabled == false){
			delete del;
		}
	}
}

void CTaskManager::Destory(){
	//�|�C���^�ϐ��^�X�N���쐬���A���X�g�̐擪�A�h���X��������
	CTask*task = mHead.mpNext;
	//�|�C���^�ϐ��^�X�N�̎��̃|�C���^��false�Ŗ����ԁA�J��Ԃ�
	while (task->mpNext){
		//�|�C���^�ϐ��폜���쐬���A�|�C���^�ϐ��^�X�N��������
		CTask*del = task;
		//�|�C���^�ϐ��^�X�N�ɁA�|�C���^�ϐ��^�X�N�̎��̃|�C���^��������
		task = task->mpNext;
		//delete�|�C���^�ϐ��폜
		delete del;
	}
}