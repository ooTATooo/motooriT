#pragma once

class KdLessonShader
{
public:

    //================================================
    // �������E���
    //================================================

    // ������
    bool Init();
    // ���
    void Release();

    // �f�X�g���N�^�Ŏ����ŉ������悤�ɂ���
    ~KdLessonShader() { Release(); }

    //================================================
    // �`�揀��
    //================================================
    // �A�e������I�u�W�F�N�g����`�悷��O��ɍs��
    void BeginLessonShader();
    void EndLessonShader();

    //================================================
    // �`��֐�
    //================================================
    // ���b�V���`��
    void DrawMesh(const KdMesh* mesh, const Math::Matrix& mWorld, const std::vector<KdMaterial>& materials,
        const Math::Vector4& col, const Math::Vector3& emissive);

    // ���f���f�[�^�`��F�A�j���[�V�����ɔ�Ή�
    void DrawModel(const KdModelData& rModel, const Math::Matrix& mWorld = Math::Matrix::Identity,
        const Math::Color& colRate = kWhiteColor, const Math::Vector3& emissive = Math::Vector3::Zero);

private:

    ID3D11VertexShader* m_VS            = nullptr;  // ���_�V�F�[�_�[
    ID3D11PixelShader*  m_PS            = nullptr;  // �s�N�Z���V�F�[�_�[

    ID3D11InputLayout*  m_inputLayout   = nullptr;  // ���_���̓��C�A�E�g

    
};
