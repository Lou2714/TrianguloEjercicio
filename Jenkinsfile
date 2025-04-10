pipeline {
    agent {
        label 'linux'
    }
    environment { 
        REPO_PRUEBAS = 'https://github.com/Lou2714/PruebasCatch2.git'
        REPO_ESTUDIANTE = 'https://github.com/Lou2714/TrianguloEjercicio.git'
        REPO_PRUEBAS_CREDENTIALS = credentials('ProbandoJenkins')
    }
    stages{
        stage('Checking SCM'){
            steps{
                checkout scm
            }
        }
        stage('Getting test repository'){
            steps{
                sh "git clone --branch main ${REPO_PRUEBAS}"
            }
        }
        stage('Move test directory'){
            steps{
                script{
                    def repoURL = sh(script: "echo ${REPO_PRUEBAS}", returnStdout: true).trim()
                    def reponame = repoURL.split('/').last().replace('.git', '')
                    echo "${reponame}"
                    //sh 'cd repos && ls -la'

                    sh("""
                        mv "${reponame}/" /home/testingVM/workspace/Prueba 
                    """) 
                }
            }
        }
        stage('Debug') {
            steps {
                //sh 'cd repos && ls -la'

                sh 'pwd && ls -la'
            }
        }
    }
    post { 
        always { 
            cleanWs()
            echo 'I will always say Hello again!'
        }
    }
}